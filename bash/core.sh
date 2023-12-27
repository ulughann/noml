#!/bin/bash

declare -A configMap
currentSegment=""

while IFS= read -r line; do
  # Trim leading and trailing whitespaces
  line=$(echo "$line" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')

  # Check if the line is not empty
  if [ -n "$line" ]; then
    # Check if the line contains '='
    if [[ "$line" == *"="* ]]; then
      IFS="=" read -r key rawValue <<< "$line"
      value=$(echo "$rawValue" | sed -e 's/^"\(.*\)"$/\1/' -e 's/^true$/true/' -e 's/^false$/false/')

      if [ -n "$currentSegment" ]; then
        configMap["$currentSegment"]["$key"]=$value
      else
        configMap["$key"]=$value
      fi
    else
      currentSegment="$line"
      declare -A configMap["$currentSegment"] # Create an associative array for the segment
    fi
  fi
done < "config_file.txt"

# Print the resulting configuration
for key in "${!configMap[@]}"; do
  if [ -n "${configMap["$key"]}" ]; then
    echo "$key: ${configMap["$key"]}"
  else
    echo "$key:"
    for subkey in "${!configMap["$key"][@]}"; do
      echo "  $subkey: ${configMap["$key"]["$subkey"]}"
    done
  fi
done

