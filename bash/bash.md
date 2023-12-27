# Noml on BASH
The Default Bash implementation of Noml.

[core.bash](./core.sh) is the main file.

The provided Bash script reads a configuration file (`config_file.txt`) and parses it to build an associative array (`configMap`). The configuration file is expected to have a structure where key-value pairs are defined, and nested segments are indicated by lines without an equal sign.

To use the script, you can follow these steps:

----

Save the script to a file, for example, `parse_config.sh`.

Make the script executable:
```sh
chmod +x parse_config.sh
```

----

Create a configuration file (`config_file.txt`) with your desired configuration. Here's an example:
```plaintext
# config_file.txt
server_name="my_server"
port=8080

database:
  host="localhost"
  username="admin"
  password="secretpassword"

logging:
  enabled=true
  level="info"
```

----

Run the script with the configuration file as an argument:
```sh
./parse_config.sh
```

----

This will parse the configuration file and display the resulting configuration:

```yaml
server_name: my_server
port: 8080
database:
  host: localhost
  username: admin
  password: secretpassword
logging:
  enabled: true
  level: info
```

----

Note: The script assumes that the configuration file follows the specified structure, and the keys do not contain spaces. Make sure to adapt the script and the configuration file format according to your specific needs.
