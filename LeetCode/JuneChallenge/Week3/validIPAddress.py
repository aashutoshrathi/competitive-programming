class Solution:
    def validIPAddress(self, IP: str) -> str:
        ipv4Stuff = IP.split('.')
        ipv6Stuff = IP.split(':')
        if len(ipv4Stuff) == 4:
            for part in ipv4Stuff:
                try:
                    int_part = int(part)
                except ValueError:
                    return "Neither"

                if int_part > 255 or int_part < 0 or (part[0] == '0' and len(part) > 1) or part[0] == '-':
                    return "Neither"
            return "IPv4"
        if len(ipv6Stuff) == 8:
            for part in ipv6Stuff:
                try:
                    decimal_part = int(part, 16)
                except ValueError:
                    return "Neither"

                if decimal_part > 65535 or len(part) > 4 or part[0] == '-':
                    return "Neither"
            return "IPv6"
        return "Neither"
