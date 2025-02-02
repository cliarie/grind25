def tokenize(input):
    if '{' not in input or '}' not in input:
        print(input)
        return
    prefix, rest = input.split('{')
    rest, suffix = rest.split('}')

    tokens = rest.split(',')
    if len(tokens) <= 1:
        print(input)
        return
    for token in tokens:
        print(prefix + token + suffix)

# tokenize input with multiple braces {a, b}{c, d}
def tokenize2(input):
    # Base case: no braces found, just print the input
    if '{' not in input or '}' not in input:
        print(input)
        return

    # Helper function to find the matching closing brace for a given opening brace
    def find_matching_brace(expression, start_index):
        open_count = 0
        for i in range(start_index, len(expression)):
            if expression[i] == '{':
                open_count += 1
            elif expression[i] == '}':
                open_count -= 1
                if open_count == 0:
                    return i
        return -1

    # Main logic for parsing nested and non-nested braces
    i = 0
    while i < len(input):
        if input[i] == '{':
            # We found the start of a brace-enclosed section
            end_index = find_matching_brace(input, i)
            if end_index == -1:
                raise ValueError("Unmatched braces in input")

            # Split the input into prefix, tokens within braces, and suffix
            prefix = input[:i]
            inside_brace = input[i+1:end_index]  # Exclude the curly braces
            suffix = input[end_index+1:]

            tokens = inside_brace.split(',')
            for token in tokens:
                # For each token, recursively process the next level with the updated input
                tokenize(prefix + token + suffix)

            return  # Exit after handling the current set of braces
        else:
            i += 1


# tokensize input with multiple nested braces {a, b{c, d}}
def tokenize3(input):
    if '{' not in input or '}' not in input:
        print(input)
        return

input = "prefix{a, b}andthen{c, d}suffix"
print(tokenize2(input))


def compress(minor: str) -> str:
    return f"{minor[0]}{len(minor) - 2}{minor[-1]}"


def merge(compressed1: str, compressed2: str) -> str:
    return f"{compressed1[0]}{int(compressed1[1]) + int(compressed2[1]) + 2}{compressed2[2]}"


def convert(url: str, threshold: int) -> str:
    major_parts = []
    for major in url.split("/"):
        minor_parts = []
        for minor in major.split("."):
            compressed = compress(minor)
            if len(minor_parts) < threshold:
                minor_parts.append(compressed)

            else:
                minor_parts[-1] = merge(minor_parts[-1], compressed)

        major_parts.append(".".join(minor_parts))

    return "/".join(major_parts)
