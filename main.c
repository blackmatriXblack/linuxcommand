#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Color codes for terminal output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

// Structure to hold command information
typedef struct {
    char name[50];
    char description[200];
    char usage[150];
    char category[30];
} Command;

// Function prototypes
void displayMenu();
void displayAllCommands(Command commands[], int count);
void displayByCategory(Command commands[], int count);
void searchCommand(Command commands[], int count);
void displayCommandDetails(Command cmd);
void clearScreen();
void pressEnterToContinue();
int initializeCommands(Command commands[]);

int main() {
    Command commands[200]; // Array to store all commands
    int commandCount = initializeCommands(commands);
    int choice;

    while (1) {
        clearScreen();
        displayMenu();

        printf("%s%sEnter your choice: %s", BOLD, CYAN, RESET);
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            printf("%s%sInvalid input! Please enter a number.%s\n", BOLD, RED, RESET);
            pressEnterToContinue();
            continue;
        }
        while (getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                displayAllCommands(commands, commandCount);
                break;
            case 2:
                displayByCategory(commands, commandCount);
                break;
            case 3:
                searchCommand(commands, commandCount);
                break;
            case 4:
                printf("%s%sThank you for using Kali Commands Browser!%s\n", BOLD, GREEN, RESET);
                exit(0);
            default:
                printf("%s%sInvalid choice! Please try again.%s\n", BOLD, RED, RESET);
                pressEnterToContinue();
        }
    }

    return 0;
}

// Initialize all Kali Linux commands
int initializeCommands(Command commands[]) {
    int index = 0;

    // Information Gathering Tools
    strcpy(commands[index].name, "nmap");
    strcpy(commands[index].description, "Network exploration tool and security/port scanner");
    strcpy(commands[index].usage, "nmap [options] <target>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "netdiscover");
    strcpy(commands[index].description, "Active/passive ARP reconnaissance tool");
    strcpy(commands[index].usage, "netdiscover -r <IP range>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "whois");
    strcpy(commands[index].description, "Query domain registration information");
    strcpy(commands[index].usage, "whois <domain>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "dig");
    strcpy(commands[index].description, "DNS lookup utility");
    strcpy(commands[index].usage, "dig <domain> [options]");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "dnsenum");
    strcpy(commands[index].description, "DNS enumeration tool for finding subdomains");
    strcpy(commands[index].usage, "dnsenum <domain>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "fierce");
    strcpy(commands[index].description, "DNS reconnaissance tool for locating non-contiguous IP space");
    strcpy(commands[index].usage, "fierce --domain <domain>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "maltego");
    strcpy(commands[index].description, "Interactive data mining tool for link analysis");
    strcpy(commands[index].usage, "maltego");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "recon-ng");
    strcpy(commands[index].description, "Full-featured reconnaissance framework");
    strcpy(commands[index].usage, "recon-ng");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "theharvester");
    strcpy(commands[index].description, "E-mail, subdomain and people names harvester");
    strcpy(commands[index].usage, "theharvester -d <domain> -b <source>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "shodan");
    strcpy(commands[index].description, "Command-line tool for Shodan search engine");
    strcpy(commands[index].usage, "shodan search <query>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "masscan");
    strcpy(commands[index].description, "Mass IP port scanner for Internet-scale scanning");
    strcpy(commands[index].usage, "masscan <IP range> -p<ports>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "dmitry");
    strcpy(commands[index].description, "Deepmagic Information Gathering Tool");
    strcpy(commands[index].usage, "dmitry [options] <target>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "enum4linux");
    strcpy(commands[index].description, "Tool for enumerating information from Windows and Samba systems");
    strcpy(commands[index].usage, "enum4linux <target>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "nbtscan");
    strcpy(commands[index].description, "NetBIOS scanner for Windows network enumeration");
    strcpy(commands[index].usage, "nbtscan <IP range>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "smbclient");
    strcpy(commands[index].description, "FTP-like client to access SMB/CIFS resources");
    strcpy(commands[index].usage, "smbclient //<server>/<share>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "smtp-user-enum");
    strcpy(commands[index].description, "Username enumeration tool for SMTP servers");
    strcpy(commands[index].usage, "smtp-user-enum -M <mode> -U <users> -t <target>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "snmp-check");
    strcpy(commands[index].description, "SNMP device information enumeration tool");
    strcpy(commands[index].usage, "snmp-check <target>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "amass");
    strcpy(commands[index].description, "In-depth DNS enumeration and network mapping");
    strcpy(commands[index].usage, "amass enum -d <domain>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "sublist3r");
    strcpy(commands[index].description, "Fast subdomains enumeration tool");
    strcpy(commands[index].usage, "sublist3r -d <domain>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    strcpy(commands[index].name, "traceroute");
    strcpy(commands[index].description, "Print the route packets take to network host");
    strcpy(commands[index].usage, "traceroute <host>");
    strcpy(commands[index].category, "Information Gathering");
    index++;

    // Vulnerability Analysis
    strcpy(commands[index].name, "nikto");
    strcpy(commands[index].description, "Web server scanner for vulnerabilities");
    strcpy(commands[index].usage, "nikto -h <host>");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    strcpy(commands[index].name, "openvas");
    strcpy(commands[index].description, "Comprehensive vulnerability scanner");
    strcpy(commands[index].usage, "openvas-start");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    strcpy(commands[index].name, "sqlmap");
    strcpy(commands[index].description, "Automatic SQL injection and database takeover tool");
    strcpy(commands[index].usage, "sqlmap -u <URL>");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    strcpy(commands[index].name, "wpscan");
    strcpy(commands[index].description, "WordPress vulnerability scanner");
    strcpy(commands[index].usage, "wpscan --url <URL>");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    strcpy(commands[index].name, "skipfish");
    strcpy(commands[index].description, "Active web application security reconnaissance tool");
    strcpy(commands[index].usage, "skipfish -o <output_dir> <URL>");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    strcpy(commands[index].name, "legion");
    strcpy(commands[index].description, "Open source penetration testing framework");
    strcpy(commands[index].usage, "legion");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    strcpy(commands[index].name, "nessus");
    strcpy(commands[index].description, "Proprietary vulnerability scanner");
    strcpy(commands[index].usage, "nessus");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    strcpy(commands[index].name, "lynis");
    strcpy(commands[index].description, "Security auditing tool for Unix-based systems");
    strcpy(commands[index].usage, "lynis audit system");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    strcpy(commands[index].name, "uniscan");
    strcpy(commands[index].description, "Simple remote file inclusion and local file inclusion scanner");
    strcpy(commands[index].usage, "uniscan -u <URL> -qweds");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    strcpy(commands[index].name, "golismero");
    strcpy(commands[index].description, "Open source framework for security testing");
    strcpy(commands[index].usage, "golismero scan <target>");
    strcpy(commands[index].category, "Vulnerability Analysis");
    index++;

    // Wireless Attacks
    strcpy(commands[index].name, "aircrack-ng");
    strcpy(commands[index].description, "WiFi security auditing tools suite");
    strcpy(commands[index].usage, "aircrack-ng <capture_file>");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "airodump-ng");
    strcpy(commands[index].description, "Wireless packet capture tool");
    strcpy(commands[index].usage, "airodump-ng <interface>");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "aireplay-ng");
    strcpy(commands[index].description, "Wireless packet injection tool");
    strcpy(commands[index].usage, "aireplay-ng [options] <interface>");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "airmon-ng");
    strcpy(commands[index].description, "Enable monitor mode on wireless interfaces");
    strcpy(commands[index].usage, "airmon-ng start <interface>");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "reaver");
    strcpy(commands[index].description, "WPS brute force attack tool");
    strcpy(commands[index].usage, "reaver -i <interface> -b <BSSID>");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "wifite");
    strcpy(commands[index].description, "Automated wireless attack tool");
    strcpy(commands[index].usage, "wifite");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "kismet");
    strcpy(commands[index].description, "Wireless network detector, sniffer, and IDS");
    strcpy(commands[index].usage, "kismet");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "fern-wifi-cracker");
    strcpy(commands[index].description, "Wireless security auditing and attack software");
    strcpy(commands[index].usage, "fern-wifi-cracker");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "pixiewps");
    strcpy(commands[index].description, "Offline WPS brute force utility");
    strcpy(commands[index].usage, "pixiewps [options]");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "bully");
    strcpy(commands[index].description, "WPS brute force attack implementation");
    strcpy(commands[index].usage, "bully <interface> -b <BSSID>");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "wash");
    strcpy(commands[index].description, "Utility for identifying WPS enabled access points");
    strcpy(commands[index].usage, "wash -i <interface>");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "mdk3");
    strcpy(commands[index].description, "Wireless denial of service testing tool");
    strcpy(commands[index].usage, "mdk3 <interface> <mode> [options]");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    strcpy(commands[index].name, "fluxion");
    strcpy(commands[index].description, "Security auditing and social engineering research tool");
    strcpy(commands[index].usage, "fluxion");
    strcpy(commands[index].category, "Wireless Attacks");
    index++;

    // Web Applications
    strcpy(commands[index].name, "burpsuite");
    strcpy(commands[index].description, "Web application security testing platform");
    strcpy(commands[index].usage, "burpsuite");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "zaproxy");
    strcpy(commands[index].description, "OWASP Zed Attack Proxy for web app testing");
    strcpy(commands[index].usage, "zaproxy");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "dirb");
    strcpy(commands[index].description, "Web content scanner");
    strcpy(commands[index].usage, "dirb <URL> [wordlist]");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "dirbuster");
    strcpy(commands[index].description, "Multi-threaded directory and file brute forcing");
    strcpy(commands[index].usage, "dirbuster");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "gobuster");
    strcpy(commands[index].description, "Directory/file and DNS busting tool");
    strcpy(commands[index].usage, "gobuster dir -u <URL> -w <wordlist>");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "wfuzz");
    strcpy(commands[index].description, "Web application fuzzer");
    strcpy(commands[index].usage, "wfuzz [options] <URL>");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "commix");
    strcpy(commands[index].description, "Automated command injection exploitation tool");
    strcpy(commands[index].usage, "commix --url=<URL>");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "whatweb");
    strcpy(commands[index].description, "Web scanner to identify technologies");
    strcpy(commands[index].usage, "whatweb <URL>");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "xsser");
    strcpy(commands[index].description, "Automatic framework to detect and exploit XSS vulnerabilities");
    strcpy(commands[index].usage, "xsser --url <URL>");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "cadaver");
    strcpy(commands[index].description, "Command-line WebDAV client");
    strcpy(commands[index].usage, "cadaver <URL>");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "paros");
    strcpy(commands[index].description, "Java-based HTTP/HTTPS proxy for web vulnerability assessment");
    strcpy(commands[index].usage, "paros");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "webscarab");
    strcpy(commands[index].description, "Framework for analyzing HTTP and HTTPS applications");
    strcpy(commands[index].usage, "webscarab");
    strcpy(commands[index].category, "Web Applications");
    index++;

    strcpy(commands[index].name, "davtest");
    strcpy(commands[index].description, "WebDAV vulnerability scanner");
    strcpy(commands[index].usage, "davtest -url <URL>");
    strcpy(commands[index].category, "Web Applications");
    index++;

    // Exploitation Tools
    strcpy(commands[index].name, "metasploit");
    strcpy(commands[index].description, "Penetration testing framework");
    strcpy(commands[index].usage, "msfconsole");
    strcpy(commands[index].category, "Exploitation");
    index++;

    strcpy(commands[index].name, "searchsploit");
    strcpy(commands[index].description, "Exploit database search tool");
    strcpy(commands[index].usage, "searchsploit <search_term>");
    strcpy(commands[index].category, "Exploitation");
    index++;

    strcpy(commands[index].name, "beef-xss");
    strcpy(commands[index].description, "Browser exploitation framework");
    strcpy(commands[index].usage, "beef-xss");
    strcpy(commands[index].category, "Exploitation");
    index++;

    strcpy(commands[index].name, "armitage");
    strcpy(commands[index].description, "Graphical cyber attack management tool");
    strcpy(commands[index].usage, "armitage");
    strcpy(commands[index].category, "Exploitation");
    index++;

    strcpy(commands[index].name, "crackmapexec");
    strcpy(commands[index].description, "Post-exploitation tool for networks");
    strcpy(commands[index].usage, "crackmapexec <protocol> <target>");
    strcpy(commands[index].category, "Exploitation");
    index++;

    strcpy(commands[index].name, "routersploit");
    strcpy(commands[index].description, "Exploitation framework for embedded devices");
    strcpy(commands[index].usage, "rsf");
    strcpy(commands[index].category, "Exploitation");
    index++;

    strcpy(commands[index].name, "exploit-db");
    strcpy(commands[index].description, "Archive of public exploits and vulnerable software");
    strcpy(commands[index].usage, "searchsploit <keyword>");
    strcpy(commands[index].category, "Exploitation");
    index++;

    strcpy(commands[index].name, "shellnoob");
    strcpy(commands[index].description, "Shellcode writing toolkit");
    strcpy(commands[index].usage, "shellnoob [options]");
    strcpy(commands[index].category, "Exploitation");
    index++;

    // Sniffing & Spoofing
    strcpy(commands[index].name, "wireshark");
    strcpy(commands[index].description, "Network protocol analyzer");
    strcpy(commands[index].usage, "wireshark");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "tcpdump");
    strcpy(commands[index].description, "Command-line packet analyzer");
    strcpy(commands[index].usage, "tcpdump [options]");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "ettercap");
    strcpy(commands[index].description, "Comprehensive suite for MITM attacks");
    strcpy(commands[index].usage, "ettercap -G");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "bettercap");
    strcpy(commands[index].description, "Swiss army knife for network attacks");
    strcpy(commands[index].usage, "bettercap");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "arpspoof");
    strcpy(commands[index].description, "ARP spoofing tool");
    strcpy(commands[index].usage, "arpspoof -i <interface> -t <target> <gateway>");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "dsniff");
    strcpy(commands[index].description, "Collection of network auditing tools");
    strcpy(commands[index].usage, "dsniff [options]");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "responder");
    strcpy(commands[index].description, "LLMNR, NBT-NS and MDNS poisoner");
    strcpy(commands[index].usage, "responder -I <interface>");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "mitmproxy");
    strcpy(commands[index].description, "Interactive HTTPS proxy");
    strcpy(commands[index].usage, "mitmproxy");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "sslstrip");
    strcpy(commands[index].description, "HTTPS stripping attacks tool");
    strcpy(commands[index].usage, "sslstrip -l <port>");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "dnsspoof");
    strcpy(commands[index].description, "DNS spoofing tool from dsniff suite");
    strcpy(commands[index].usage, "dnsspoof [options]");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    strcpy(commands[index].name, "macchanger");
    strcpy(commands[index].description, "Utility for manipulating MAC addresses");
    strcpy(commands[index].usage, "macchanger -r <interface>");
    strcpy(commands[index].category, "Sniffing & Spoofing");
    index++;

    // Password Attacks
    strcpy(commands[index].name, "hydra");
    strcpy(commands[index].description, "Fast network logon cracker");
    strcpy(commands[index].usage, "hydra [options] <target> <protocol>");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "john");
    strcpy(commands[index].description, "John the Ripper password cracker");
    strcpy(commands[index].usage, "john [options] <password_file>");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "hashcat");
    strcpy(commands[index].description, "Advanced password recovery tool");
    strcpy(commands[index].usage, "hashcat [options] <hash_file> <wordlist>");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "medusa");
    strcpy(commands[index].description, "Speedy, parallel password cracker");
    strcpy(commands[index].usage, "medusa [options]");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "crunch");
    strcpy(commands[index].description, "Wordlist generator");
    strcpy(commands[index].usage, "crunch <min> <max> [charset] -o <output>");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "cewl");
    strcpy(commands[index].description, "Custom wordlist generator from websites");
    strcpy(commands[index].usage, "cewl <URL>");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "ophcrack");
    strcpy(commands[index].description, "Windows password cracker using rainbow tables");
    strcpy(commands[index].usage, "ophcrack");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "mimikatz");
    strcpy(commands[index].description, "Extract passwords from Windows memory");
    strcpy(commands[index].usage, "mimikatz");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "patator");
    strcpy(commands[index].description, "Multi-purpose brute-forcer with modular design");
    strcpy(commands[index].usage, "patator <module> [options]");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "ncrack");
    strcpy(commands[index].description, "High-speed network authentication cracking tool");
    strcpy(commands[index].usage, "ncrack [options] <target>");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "chntpw");
    strcpy(commands[index].description, "Offline Windows password and registry editor");
    strcpy(commands[index].usage, "chntpw [options] <sam_file>");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    strcpy(commands[index].name, "hash-identifier");
    strcpy(commands[index].description, "Identify different types of hashes");
    strcpy(commands[index].usage, "hash-identifier");
    strcpy(commands[index].category, "Password Attacks");
    index++;

    // Reverse Engineering
    strcpy(commands[index].name, "ghidra");
    strcpy(commands[index].description, "Software reverse engineering framework");
    strcpy(commands[index].usage, "ghidra");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    strcpy(commands[index].name, "radare2");
    strcpy(commands[index].description, "Unix-like reverse engineering framework");
    strcpy(commands[index].usage, "radare2 <file>");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    strcpy(commands[index].name, "gdb");
    strcpy(commands[index].description, "GNU Debugger");
    strcpy(commands[index].usage, "gdb <program>");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    strcpy(commands[index].name, "objdump");
    strcpy(commands[index].description, "Display information from object files");
    strcpy(commands[index].usage, "objdump [options] <file>");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    strcpy(commands[index].name, "strings");
    strcpy(commands[index].description, "Print strings of printable characters in files");
    strcpy(commands[index].usage, "strings <file>");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    strcpy(commands[index].name, "strace");
    strcpy(commands[index].description, "Trace system calls and signals");
    strcpy(commands[index].usage, "strace <command>");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    strcpy(commands[index].name, "ltrace");
    strcpy(commands[index].description, "Library call tracer");
    strcpy(commands[index].usage, "ltrace <command>");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    strcpy(commands[index].name, "edb-debugger");
    strcpy(commands[index].description, "Cross-platform AArch32/x86/x86-64 debugger");
    strcpy(commands[index].usage, "edb");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    strcpy(commands[index].name, "ollydbg");
    strcpy(commands[index].description, "32-bit assembler level debugger for Windows");
    strcpy(commands[index].usage, "ollydbg");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    strcpy(commands[index].name, "hopper");
    strcpy(commands[index].description, "Reverse engineering tool for OS X and Linux");
    strcpy(commands[index].usage, "hopper");
    strcpy(commands[index].category, "Reverse Engineering");
    index++;

    // Forensics
    strcpy(commands[index].name, "autopsy");
    strcpy(commands[index].description, "Digital forensics platform");
    strcpy(commands[index].usage, "autopsy");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "binwalk");
    strcpy(commands[index].description, "Firmware analysis tool");
    strcpy(commands[index].usage, "binwalk <file>");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "foremost");
    strcpy(commands[index].description, "File recovery tool");
    strcpy(commands[index].usage, "foremost -i <input_file>");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "volatility");
    strcpy(commands[index].description, "Memory forensics framework");
    strcpy(commands[index].usage, "volatility -f <memory_dump> <plugin>");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "bulk_extractor");
    strcpy(commands[index].description, "Extract features from disk images");
    strcpy(commands[index].usage, "bulk_extractor -o <output_dir> <input>");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "guymager");
    strcpy(commands[index].description, "Forensic imaging tool");
    strcpy(commands[index].usage, "guymager");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "exiftool");
    strcpy(commands[index].description, "Read and write meta information in files");
    strcpy(commands[index].usage, "exiftool <file>");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "scalpel");
    strcpy(commands[index].description, "Fast file carver for digital forensics");
    strcpy(commands[index].usage, "scalpel <disk_image> -o <output_dir>");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "photorec");
    strcpy(commands[index].description, "File data recovery software");
    strcpy(commands[index].usage, "photorec");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "testdisk");
    strcpy(commands[index].description, "Partition recovery and disk undelete utility");
    strcpy(commands[index].usage, "testdisk");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "dc3dd");
    strcpy(commands[index].description, "Patched version of dd for forensic acquisition");
    strcpy(commands[index].usage, "dc3dd if=<input> of=<output>");
    strcpy(commands[index].category, "Forensics");
    index++;

    strcpy(commands[index].name, "sleuthkit");
    strcpy(commands[index].description, "Collection of command line digital forensics tools");
    strcpy(commands[index].usage, "Various commands (fls, icat, etc.)");
    strcpy(commands[index].category, "Forensics");
    index++;

    // Social Engineering
    strcpy(commands[index].name, "setoolkit");
    strcpy(commands[index].description, "Social Engineering Toolkit");
    strcpy(commands[index].usage, "setoolkit");
    strcpy(commands[index].category, "Social Engineering");
    index++;

    strcpy(commands[index].name, "king-phisher");
    strcpy(commands[index].description, "Phishing campaign toolkit");
    strcpy(commands[index].usage, "king-phisher");
    strcpy(commands[index].category, "Social Engineering");
    index++;

    strcpy(commands[index].name, "gophish");
    strcpy(commands[index].description, "Open-source phishing framework");
    strcpy(commands[index].usage, "gophish");
    strcpy(commands[index].category, "Social Engineering");
    index++;

    // Post Exploitation
    strcpy(commands[index].name, "powersploit");
    strcpy(commands[index].description, "PowerShell post-exploitation framework");
    strcpy(commands[index].usage, "Import-Module PowerSploit");
    strcpy(commands[index].category, "Post Exploitation");
    index++;

    strcpy(commands[index].name, "weevely");
    strcpy(commands[index].description, "Weaponized web shell");
    strcpy(commands[index].usage, "weevely generate <password> <path>");
    strcpy(commands[index].category, "Post Exploitation");
    index++;

    strcpy(commands[index].name, "proxychains");
    strcpy(commands[index].description, "Redirect connections through proxy servers");
    strcpy(commands[index].usage, "proxychains <command>");
    strcpy(commands[index].category, "Post Exploitation");
    index++;

    strcpy(commands[index].name, "netcat");
    strcpy(commands[index].description, "Networking utility for reading/writing network connections");
    strcpy(commands[index].usage, "nc [options] <host> <port>");
    strcpy(commands[index].category, "Post Exploitation");
    index++;

    strcpy(commands[index].name, "empire");
    strcpy(commands[index].description, "Post-exploitation framework for PowerShell and Python");
    strcpy(commands[index].usage, "empire");
    strcpy(commands[index].category, "Post Exploitation");
    index++;

    strcpy(commands[index].name, "pupy");
    strcpy(commands[index].description, "Cross-platform remote administration tool");
    strcpy(commands[index].usage, "pupy");
    strcpy(commands[index].category, "Post Exploitation");
    index++;

    strcpy(commands[index].name, "covenant");
    strcpy(commands[index].description, ".NET command and control framework");
    strcpy(commands[index].usage, "dotnet run");
    strcpy(commands[index].category, "Post Exploitation");
    index++;

    // Reporting Tools
    strcpy(commands[index].name, "dradis");
    strcpy(commands[index].description, "Collaboration and reporting platform");
    strcpy(commands[index].usage, "dradis");
    strcpy(commands[index].category, "Reporting");
    index++;

    strcpy(commands[index].name, "pipal");
    strcpy(commands[index].description, "Password analysis tool");
    strcpy(commands[index].usage, "pipal <password_file>");
    strcpy(commands[index].category, "Reporting");
    index++;

    strcpy(commands[index].name, "cutycapt");
    strcpy(commands[index].description, "Utility to capture WebKit's rendering of a web page");
    strcpy(commands[index].usage, "cutycapt --url=<URL> --out=<file>");
    strcpy(commands[index].category, "Reporting");
    index++;

    strcpy(commands[index].name, "recordmydesktop");
    strcpy(commands[index].description, "Desktop session recorder");
    strcpy(commands[index].usage, "recordmydesktop");
    strcpy(commands[index].category, "Reporting");
    index++;

    // Hardware Hacking
    strcpy(commands[index].name, "arduino");
    strcpy(commands[index].description, "Arduino IDE for hardware programming");
    strcpy(commands[index].usage, "arduino");
    strcpy(commands[index].category, "Hardware Hacking");
    index++;

    strcpy(commands[index].name, "sakis3g");
    strcpy(commands[index].description, "3G/UMTS connection management");
    strcpy(commands[index].usage, "sakis3g connect");
    strcpy(commands[index].category, "Hardware Hacking");
    index++;

    strcpy(commands[index].name, "android-sdk");
    strcpy(commands[index].description, "Android software development kit");
    strcpy(commands[index].usage, "adb <command>");
    strcpy(commands[index].category, "Hardware Hacking");
    index++;

    strcpy(commands[index].name, "apktool");
    strcpy(commands[index].description, "Tool for reverse engineering Android APK files");
    strcpy(commands[index].usage, "apktool d <apk_file>");
    strcpy(commands[index].category, "Hardware Hacking");
    index++;

    // System Services
    strcpy(commands[index].name, "systemctl");
    strcpy(commands[index].description, "Control systemd services");
    strcpy(commands[index].usage, "systemctl <action> <service>");
    strcpy(commands[index].category, "System Services");
    index++;

    strcpy(commands[index].name, "service");
    strcpy(commands[index].description, "Run System V init script");
    strcpy(commands[index].usage, "service <service> <action>");
    strcpy(commands[index].category, "System Services");
    index++;

    strcpy(commands[index].name, "update-rc.d");
    strcpy(commands[index].description, "Install and remove System-V style init script links");
    strcpy(commands[index].usage, "update-rc.d <service> <action>");
    strcpy(commands[index].category, "System Services");
    index++;

    // Networking Tools
    strcpy(commands[index].name, "curl");
    strcpy(commands[index].description, "Transfer data from or to a server");
    strcpy(commands[index].usage, "curl [options] <URL>");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "wget");
    strcpy(commands[index].description, "Non-interactive network downloader");
    strcpy(commands[index].usage, "wget [options] <URL>");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "ping");
    strcpy(commands[index].description, "Send ICMP ECHO_REQUEST packets to network hosts");
    strcpy(commands[index].usage, "ping <host>");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "netstat");
    strcpy(commands[index].description, "Print network connections and routing tables");
    strcpy(commands[index].usage, "netstat [options]");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "ss");
    strcpy(commands[index].description, "Utility to investigate sockets");
    strcpy(commands[index].usage, "ss [options]");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "iptables");
    strcpy(commands[index].description, "Administration tool for IPv4 packet filtering");
    strcpy(commands[index].usage, "iptables [options]");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "ifconfig");
    strcpy(commands[index].description, "Configure network interface parameters");
    strcpy(commands[index].usage, "ifconfig [interface] [options]");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "ip");
    strcpy(commands[index].description, "Show/manipulate routing, devices, and tunnels");
    strcpy(commands[index].usage, "ip [options] <object> <command>");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "route");
    strcpy(commands[index].description, "Show/manipulate IP routing table");
    strcpy(commands[index].usage, "route [options]");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "arp");
    strcpy(commands[index].description, "Manipulate ARP cache");
    strcpy(commands[index].usage, "arp [options]");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "host");
    strcpy(commands[index].description, "DNS lookup utility");
    strcpy(commands[index].usage, "host <hostname>");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "nslookup");
    strcpy(commands[index].description, "Query Internet name servers interactively");
    strcpy(commands[index].usage, "nslookup <hostname>");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "hping3");
    strcpy(commands[index].description, "Network tool to send custom TCP/IP packets");
    strcpy(commands[index].usage, "hping3 [options] <target>");
    strcpy(commands[index].category, "Networking");
    index++;

    strcpy(commands[index].name, "socat");
    strcpy(commands[index].description, "Multipurpose relay for bidirectional data transfer");
    strcpy(commands[index].usage, "socat [options] <address> <address>");
    strcpy(commands[index].category, "Networking");
    index++;

    return index;
}

// Display main menu
void displayMenu() {
    printf("\n");
    printf("%s%s============================================================%s\n", BOLD, CYAN, RESET);
    printf("%s%s         KALI LINUX COMMANDS BROWSER v1.0                  %s\n", BOLD, CYAN, RESET);
    printf("%s%s============================================================%s\n", BOLD, CYAN, RESET);
    printf("\n");
    printf("%s%s[1]%s Display All Commands\n", BOLD, GREEN, RESET);
    printf("%s%s[2]%s Browse Commands by Category\n", BOLD, GREEN, RESET);
    printf("%s%s[3]%s Search for a Command\n", BOLD, GREEN, RESET);
    printf("%s%s[4]%s Exit\n", BOLD, RED, RESET);
    printf("\n");
}

// Display all commands
void displayAllCommands(Command commands[], int count) {
    clearScreen();
    printf("\n%s%s============================================================%s\n", BOLD, MAGENTA, RESET);
    printf("%s%s              ALL KALI LINUX COMMANDS (%d)                %s\n", BOLD, MAGENTA, count, RESET);
    printf("%s%s============================================================%s\n\n", BOLD, MAGENTA, RESET);

    for (int i = 0; i < count; i++) {
        displayCommandDetails(commands[i]);
        printf("\n");
    }

    pressEnterToContinue();
}

// Display commands by category
void displayByCategory(Command commands[], int count) {
    char categories[20][30];
    int categoryCount = 0;

    // Extract unique categories
    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < categoryCount; j++) {
            if (strcmp(categories[j], commands[i].category) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(categories[categoryCount], commands[i].category);
            categoryCount++;
        }
    }

    clearScreen();
    printf("\n%s%s============================================================%s\n", BOLD, YELLOW, RESET);
    printf("%s%s                COMMAND CATEGORIES                         %s\n", BOLD, YELLOW, RESET);
    printf("%s%s============================================================%s\n\n", BOLD, YELLOW, RESET);

    for (int i = 0; i < categoryCount; i++) {
        printf("%s%s[%d]%s %s\n", BOLD, GREEN, i + 1, RESET, categories[i]);
    }
    printf("%s%s[0]%s Back to Main Menu\n\n", BOLD, RED, RESET);

    printf("%s%sEnter category number: %s", BOLD, CYAN, RESET);
    int choice;
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf("%s%sInvalid input!%s\n", BOLD, RED, RESET);
        pressEnterToContinue();
        return;
    }
    while (getchar() != '\n');

    if (choice == 0) return;
    if (choice < 1 || choice > categoryCount) {
        printf("%s%sInvalid choice!%s\n", BOLD, RED, RESET);
        pressEnterToContinue();
        return;
    }

    clearScreen();
    printf("\n%s%s============================================================%s\n", BOLD, MAGENTA, RESET);
    printf("%s%s              CATEGORY: %s                    %s\n", BOLD, MAGENTA, categories[choice - 1], RESET);
    printf("%s%s============================================================%s\n\n", BOLD, MAGENTA, RESET);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(commands[i].category, categories[choice - 1]) == 0) {
            displayCommandDetails(commands[i]);
            printf("\n");
            found++;
        }
    }

    printf("%s%sTotal commands in this category: %d%s\n", BOLD, CYAN, found, RESET);
    pressEnterToContinue();
}

// Search for a command
void searchCommand(Command commands[], int count) {
    char searchTerm[50];

    clearScreen();
    printf("\n%s%s============================================================%s\n", BOLD, CYAN, RESET);
    printf("%s%s                  SEARCH COMMANDS                          %s\n", BOLD, CYAN, RESET);
    printf("%s%s============================================================%s\n\n", BOLD, CYAN, RESET);

    printf("%s%sEnter search term (name or keyword): %s", BOLD, YELLOW, RESET);
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    // Convert search term to lowercase
    for (int i = 0; searchTerm[i]; i++) {
        searchTerm[i] = tolower(searchTerm[i]);
    }

    clearScreen();
    printf("\n%s%s============================================================%s\n", BOLD, GREEN, RESET);
    printf("%s%s         SEARCH RESULTS FOR: \"%s\"                     %s\n", BOLD, GREEN, searchTerm, RESET);
    printf("%s%s============================================================%s\n\n", BOLD, GREEN, RESET);

    int found = 0;
    for (int i = 0; i < count; i++) {
        char nameLower[50], descLower[200];

        // Convert command name and description to lowercase
        strcpy(nameLower, commands[i].name);
        strcpy(descLower, commands[i].description);
        for (int j = 0; nameLower[j]; j++) nameLower[j] = tolower(nameLower[j]);
        for (int j = 0; descLower[j]; j++) descLower[j] = tolower(descLower[j]);

        if (strstr(nameLower, searchTerm) != NULL || strstr(descLower, searchTerm) != NULL) {
            displayCommandDetails(commands[i]);
            printf("\n");
            found++;
        }
    }

    if (found == 0) {
        printf("%s%sNo commands found matching \"%s\"%s\n", BOLD, RED, searchTerm, RESET);
    } else {
        printf("%s%sTotal commands found: %d%s\n", BOLD, CYAN, found, RESET);
    }

    pressEnterToContinue();
}

// Display detailed information about a command
void displayCommandDetails(Command cmd) {
    printf("%s%s+-----------------------------------------------------------+%s\n", BOLD, BLUE, RESET);
    printf("%s%s| Command: %s%-48s%s%s|%s\n", BOLD, BLUE, GREEN, cmd.name, BLUE, BOLD, RESET);
    printf("%s%s+-----------------------------------------------------------+%s\n", BOLD, BLUE, RESET);
    printf("%s%s| Category: %-48s%s%s|%s\n", BOLD, BLUE, cmd.category, BLUE, BOLD, RESET);
    printf("%s%s| Description: %-45s%s%s|%s\n", BOLD, BLUE, cmd.description, BLUE, BOLD, RESET);
    printf("%s%s| Usage: %-51s%s%s|%s\n", BOLD, BLUE, cmd.usage, BLUE, BOLD, RESET);
    printf("%s%s+-----------------------------------------------------------+%s\n", BOLD, BLUE, RESET);
}

// Clear screen (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Wait for user input to continue
void pressEnterToContinue() {
    printf("\n%s%sPress ENTER to continue...%s", BOLD, YELLOW, RESET);
    getchar();
}