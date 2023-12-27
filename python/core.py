def parse(code):
    config_map = {}
    current_segment = None

    for line in code.split('\n'):
        line = line.strip()
        if line:
            if '=' in line:
                key, raw_value = map(str.strip, line.split('='))
                value = raw_value[1:-1] if raw_value.startswith('"') and raw_value.endswith('"') else \
                        float(raw_value) if raw_value.replace('.', '', 1).isdigit() else \
                        True if raw_value.lower() == 'true' else \
                        False if raw_value.lower() == 'false' else \
                        raw_value
                if current_segment: config_map[current_segment][key] = value
                else: config_map[key] = value
            else:
                current_segment = line
                config_map[current_segment] = {}

    return config_map