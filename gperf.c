/* C code produced by gperf version 2.7 */
/* Command-line: gperf -c -p -t -T -g -j1 -o -K rwd -N is_reserved indent.gperf  */

#define TOTAL_KEYWORDS 31
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 8
#define MIN_HASH_VALUE 4
#define MAX_HASH_VALUE 42
/* maximum key range = 39, duplicates = 0 */

#ifdef __GNUC__
__inline
#endif
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static unsigned char asso_values[] =
    {
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43,  6,  9,
      10,  0, 16,  5,  4, 24, 43,  0, 20,  4,
      20,  0, 43, 43,  6,  0,  0, 10, 10,  2,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
      43, 43, 43, 43, 43, 43
    };
  return len + asso_values[(unsigned char)str[len - 1]] + asso_values[(unsigned char)str[0]];
}

#ifdef __GNUC__
__inline
#endif
struct templ *
is_reserved (str, len)
     register const char *str;
     register unsigned int len;
{
  static struct templ wordlist[] =
    {
      {""}, {""}, {""}, {""},
      {"else", rw_sp_nparen,},
      {"short", rw_decl,},
      {"struct", rw_struct_like,},
      {"while", rw_sp_paren,},
      {"enum", rw_enum,},
      {"goto", rw_break,},
      {"switch", rw_switch,},
      {"break", rw_break,},
      {"do", rw_sp_nparen,},
      {"case", rw_case,},
      {"const", rw_decl,},
      {"static", rw_decl,},
      {"double", rw_decl,},
      {"default", rw_case,},
      {"volatile", rw_decl,},
      {"char", rw_decl,},
      {"register", rw_decl,},
      {"float", rw_decl,},
      {"sizeof", rw_sizeof,},
      {"typedef", rw_decl,},
      {"void", rw_decl,},
      {"for", rw_sp_paren,},
      {"extern", rw_decl,},
      {"int", rw_decl,},
      {"unsigned", rw_decl,},
      {"long", rw_decl,},
      {""},
      {"global", rw_decl,},
      {"return", rw_return,},
      {""}, {""},
      {"union", rw_struct_like,},
      {"va_dcl", rw_decl,},
      {""}, {""}, {""}, {""}, {""},
      {"if", rw_sp_paren,}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].rwd;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}
