def shorten_minor_part(part):
    """
    Shorten each minor part by compressing it to the first character followed by the length of the remaining characters.
    Example: 'checkout' -> 'c6t'
    """
    if len(part) <= 2:
        return part
    return f"{part[0]}{len(part[1:-1])}{part[-1]}"


def compress_string(url, minor_parts_limit, total_minor_parts_limit):
    """
    Compress the URL according to the rules:
    - Compress each minor part.
    - Limit the number of minor parts in each major part.
    - Ensure total minor parts across the entire URL does not exceed a given limit.

    Parameters:
        url (str): The input URL string.
        minor_parts_limit (int): Maximum number of minor parts per major part.
        total_minor_parts_limit (int): Maximum number of minor parts across the entire URL.
    """
    # Split the string into major parts
    major_parts = url.split('/')

    # Initialize compressed parts and total minor parts count
    compressed_url = []
    total_minor_parts_count = 0

    for major_part in major_parts:
        # Split each major part into minor parts
        minor_parts = major_part.split('.')

        # Compress each minor part
        compressed_minor_parts = [shorten_minor_part(part) for part in minor_parts]

        # Respect the minor parts limit per major part
        compressed_minor_parts = compressed_minor_parts[:minor_parts_limit]

        # Count total minor parts, respecting the overall limit
        if total_minor_parts_count + len(compressed_minor_parts) > total_minor_parts_limit:
            # Trim the minor parts to fit within the total limit
            remaining_slots = total_minor_parts_limit - total_minor_parts_count
            compressed_minor_parts = compressed_minor_parts[:remaining_slots]

        # Add the compressed major part to the result
        compressed_url.append('.'.join(compressed_minor_parts))

        # Update the total minor parts count
        total_minor_parts_count += len(compressed_minor_parts)

        # If we have reached the total minor parts limit, stop processing further
        if total_minor_parts_count >= total_minor_parts_limit:
            break

    # Join the compressed major parts back into a single URL
    return '/'.join(compressed_url)


# Example usage based on the instructions and image
url1 = "stripe.com/payments/checkout/customer.john.doe"
minor_parts_limit1 = 2
total_minor_parts_limit1 = 7  # Assuming the total limit across all parts

url2 = "www.api.stripe.com/checkout"
minor_parts_limit2 = 3
total_minor_parts_limit2 = 7  # Assuming the total limit across all parts

# Compress the URLs
compressed_url1 = compress_string(url1, minor_parts_limit1, total_minor_parts_limit1)
compressed_url2 = compress_string(url2, minor_parts_limit2, total_minor_parts_limit2)

print(compressed_url1, compressed_url2)
