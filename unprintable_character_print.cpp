<snippet>
	<content><![CDATA[

void printUnprintableString(const std::string& input) {
    for (char ch : input) {
        if (ch >= 32 && ch <= 126) {
            // Printable characters (ASCII 32 to 126) can be printed as is
            std::cerr << ch;
        } else {
            // Unprintable characters are printed using \x followed by the ASCII value in hexadecimal
            std::cerr << "\\\x" << std::hex << static_cast<int>(ch);
        }
    }
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>unprintable character string print</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
