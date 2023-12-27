<img align="right" src="NOML.png" alt="TOML logo">

# NOML

Non Overcomplicated, Minimal Language

By a high school student, under 25 LOC.

> This repository contains everything there is to know about Noml because there isn't much to know anyway.

## Objectives

Noml aims to *over*simplify the *overcomplicated* world of config files. It is a *minimal* language that is ***non overcomplicated** by definition. It also aims to be tiny, with the entire language being under 25 lines of code.

## Contents

- [NOML](#noml)
  - [Objectives](#objectives)
  - [Contents](#contents)
  - [Example](#example)
  - [Features](#features)
    - [Small](#small)

## Example
```py
title = NOML Example

owner
  name = Tom Preston-Werner

database
  server = 192.168.1.1
  enabled = true
```

## Features

### Small

No need to brag about how small it is, here have the entire source code.
```javascript
export function parse(code) {
  const configMap = {};
  let currentSegment;

  code.split`\n`.forEach((line = line.trim()) => {
    if (line) {
      if (line.includes("=")) {
        const [key, rawValue] = line.split("=").map((str) => str.trim());
        const value =
          rawValue.startsWith('"') && rawValue.endsWith('"')
            ? rawValue.slice(1, -1)
            : !isNaN(rawValue)
            ? +rawValue
            : rawValue.toLowerCase() === "true"
            ? true
            : rawValue.toLowerCase() === "false"
            ? false
            : rawValue;

        if (currentSegment) configMap[currentSegment][key] = value;
        else configMap[key] = value;
      } else (currentSegment = line), (configMap[currentSegment] = {});
    }
  });

  return configMap;
}
```
