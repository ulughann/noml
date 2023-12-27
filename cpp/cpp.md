# Noml on CPP
The Default Cpp implementation of Noml.

[core.cpp](./core.cpp) is the main file.

-----
This C++ code is designed to read a configuration file in a specific format and store its contents in a nested unordered_map. The configuration file is expected to have sections denoted by lines without '=' (e.g., [section_name]), followed by key-value pairs within each section.

To use this code, follow these steps:

**Create a Configuration File:**
	Create a configuration file, for example, "config_file.txt", in the format specified by the code. Here's an example:

```
[General]
name = "John Doe"
age = 25
is_student = true

[Address]
city = "New York"
zip_code = 10001
```

----

 **Understand the Code:** 
	 The code reads the configuration file, trims whitespace, and stores the key-value pairs in the `configMap` variable, which is an unordered_map with nested values. The code then prints the resulting configuration.

----

**Compile and Run:** 
	Save the code in a file, for example, "core.cpp". Then, compile it using a C++ compiler. For instance, using g++, you can do:
	
```sh
g++ -o config_parser core.cpp
```

After successful compilation, run the executable:

```sh
./config_parser
```

----

**Review the Output:** 
	The program will read the configuration file and print the parsed values to the console. The output will be similar to:
	
```plaintext
General:
  name: John Doe
  age: 25
  is_student: 1
Address:
  city: New York
  zip_code: 10001
```

Note: The boolean value `is_student` is printed as `1` for `true` and `0` for `false`.

----

**Adjust for Your Configuration File:** 
	Modify the code as needed based on your specific configuration file format. You may need to adapt the code if your configuration file has a different structure or if you want to support additional data types.


Remember to handle errors appropriately in a production setting, such as checking whether the file is successfully opened and whether the key-value pairs are correctly formatted.