char* send_string_rewrite_symbol(char c) {
    static char str_plus[] = "-";
    static char str_colon[] = SS_LSFT(".");
    static char str_dash[] = "/";
    static char str_at[] = SS_RALT("2");
    static char str_equals[] = "\\";

    switch (c) {
        case '+': return str_plus;
        case ':': return str_colon;
        case '-': return str_dash;
        case '@': return str_at;
        case '=': return str_equals;
        default: return 0;
    }
}

void append(char* buffer, int buffer_size, int* index, char* str) {
    int i = 0;
    while (*str != '\0') {
        if (*index >= buffer_size - 1) {
            dprintf(
                "append failed: buffer is not larged enough. Tried to write to %d when buffer size is %d",
                *index,
                buffer_size
            );
            return;
        }
        buffer[(*index)++] = *str++;
        i++;
    }
}

/**
 * Since I am using a Norwegian keyboard, most often with a Colemak layout, we must rewrite the
 * characters before they are sent to send_string. If the colemak layer is used, we assume the OS is
 * running with a Norwegian layout. Then only the symbols need to be rewritten.
 *
 * If the colemak layer is not used, then we assume the OS is running with Norwegian(Colemak), and we
 * must therefore rewrite most of the keys as well.
 *
 * The input buffer must be large enough to hold extra characters as some symbols will be encoded
 * with multiple bytes.
 */
void send_string_rewrite(
    char* buffer,
    int buffer_size,
    int colemak_layer
) {
    char read_buffer[500] = { 0 };
    if (buffer_size > sizeof(read_buffer)) {
        return;
    }

    memcpy(read_buffer, buffer, buffer_size);
    memset(buffer, 0, buffer_size);

    int j = 0;
    for (int i = 0; i < buffer_size; i++) {
        char c = read_buffer[i];
        if (c == 0) {
            break;
        }

        char* symbol = send_string_rewrite_symbol(c);
        if (symbol != 0) {
            append(buffer, buffer_size, &j, symbol);
        } else if (default_layer_state & (1 << colemak_layer)) {
            buffer[j++] = c;
        } else {
            if (c == 'o') {
                buffer[j++] = ';';
            } else if (c == 'O') {
                buffer[j++] = ':';
            } else {
                bool is_upper = c >= 'A' && c <= 'Z';
                char lower = c;
                if (is_upper) lower += 32;
                char converted = 0;

                switch (lower) {
                    case 'f': converted = 'e'; break;
                    case 'p': converted = 'r'; break;
                    case 'g': converted = 't'; break;
                    case 'j': converted = 'y'; break;
                    case 'l': converted = 'u'; break;
                    case 'u': converted = 'i'; break;
                    case 'y': converted = 'o'; break;

                    case 'r': converted = 's'; break;
                    case 's': converted = 'd'; break;
                    case 't': converted = 'f'; break;
                    case 'd': converted = 'g'; break;
                    case 'n': converted = 'j'; break;
                    case 'e': converted = 'k'; break;
                    case 'i': converted = 'l'; break;

                    case 'k': converted = 'n'; break;
                    default: converted = lower; break;
                }

                if (is_upper) converted -= 32;
                buffer[j++] = converted;
            }
        }
    }
}
