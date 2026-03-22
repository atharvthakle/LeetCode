using System;

public class Solution {
    public string ValidIPAddress(string queryIP) {
        if (queryIP.Contains(".")) {
            return IsIPv4(queryIP) ? "IPv4" : "Neither";
        }
        else if (queryIP.Contains(":")) {
            return IsIPv6(queryIP) ? "IPv6" : "Neither";
        }
        return "Neither";
    }

    private bool IsIPv4(string ip) {
        string[] parts = ip.Split('.');
        if (parts.Length != 4) return false;

        foreach (string p in parts) {
            if (p.Length == 0 || p.Length > 3) return false;

            // no leading zero
            if (p.Length > 1 && p[0] == '0') return false;

            foreach (char c in p) {
                if (!char.IsDigit(c)) return false;
            }

            int num = int.Parse(p);
            if (num < 0 || num > 255) return false;
        }

        return true;
    }

    private bool IsIPv6(string ip) {
        string[] parts = ip.Split(':');
        if (parts.Length != 8) return false;

        foreach (string p in parts) {
            if (p.Length == 0 || p.Length > 4) return false;

            foreach (char c in p) {
                if (!IsHex(c)) return false;
            }
        }

        return true;
    }

    private bool IsHex(char c) {
        return char.IsDigit(c) ||
               (c >= 'a' && c <= 'f') ||
               (c >= 'A' && c <= 'F');
    }
}
