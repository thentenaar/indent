/* C code produced by gperf version 2.7 */
/* Command-line: gperf -D -c -p -t -T -g -j1 -o -K rwd -N is_reserved_cc -H hash_cc indent-cc.gperf  */

#define TOTAL_KEYWORDS 47
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 9
#define MIN_HASH_VALUE 4
#define MAX_HASH_VALUE 70
/* maximum key range = 67, duplicates = 1 */

#ifdef __GNUC__
__inline
#endif
static unsigned int
hash_cc (str, len)
     register const char *str;
     register unsigned int len;
{
  static unsigned char asso_values[] =
    {
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71,  4, 17,
       5,  0,  9,  1, 37, 23, 71,  0,  0,  2,
      19,  7, 71, 71, 16,  4, 34, 11, 55, 31,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71
    };
  return len + asso_values[(unsigned char)str[len - 1]] + asso_values[(unsigned char)str[0]];
}

#ifdef __GNUC__
__inline
#endif
struct templ *
is_reserved_cc (str, len)
     register const char *str;
     register unsigned int len;
{
  static struct templ wordlist[] =
    {
      {"else", rw_sp_else,},
      {"long", rw_decl,},
      {"enum", rw_enum,},
      {"global", rw_decl,},
      {"bool", rw_decl,},
      {"break", rw_break,},
      {"double", rw_decl,},
      {"delete", rw_return,},
      {"goto", rw_break,},
      {"signature", rw_struct_like,},
      {"do", rw_sp_nparen,},
      {"sigof", rw_sizeof,},
      {"sizeof", rw_sizeof,},
      {"friend", rw_decl,},
      {"case", rw_case,},
      {"unsigned", rw_decl,},
      {"extern", rw_decl,},
      {"class", rw_struct_like,},
      {"static", rw_decl,},
      {"for", rw_sp_paren,},
      {"inline", rw_decl,},
      {"operator", rw_operator,},
      {"classof", rw_sizeof,},
      {"if", rw_sp_paren,},
      {"union", rw_struct_like,},
      {"while", rw_sp_paren,},
      {"char", rw_decl,},
      {"register", rw_decl,},
      {"return", rw_return,},
      {"template", rw_decl,},
      {"short", rw_decl,},
      {"struct", rw_struct_like,},
      {"default", rw_case,},
      {"switch", rw_switch,},
      {"float", rw_decl,},
      {"typeof", rw_sizeof,},
      {"typedef", rw_decl,},
      {"headof", rw_sizeof,},
      {"new", rw_return,},
      {"const", rw_decl,},
      {"catch", rw_sp_paren,},
      {"int", rw_decl,},
      {"va_dcl", rw_decl,},
      {"virtual", rw_decl,},
      {"volatile", rw_decl,},
      {"void", rw_decl,},
      {"throw", rw_return,}
    };

  static short lookup[] =
    {
       -1,  -1,  -1,  -1,   0,   1,   2,   3,   4,   5,
       -1, -63,   8,   9,  10, -41,  -2,  -1,  11,  12,
       13,  14,  -1,  -1,  15,  16,  17,  18,  19,  20,
       -1,  21,  -1,  22,  23,  24,  25,  26,  -1,  -1,
       27,  28,  29,  30,  31,  -1,  32,  33,  34,  35,
       36,  -1,  37,  38,  -1,  -1,  39,  -1,  -1,  40,
       41,  42,  43,  44,  45,  -1,  -1,  -1,  -1,  -1,
       46
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash_cc (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist[index].rwd;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
                return &wordlist[index];
            }
          else if (index < -TOTAL_KEYWORDS)
            {
              register int offset = - 1 - TOTAL_KEYWORDS - index;
              register struct templ *wordptr = &wordlist[TOTAL_KEYWORDS + lookup[offset]];
              register struct templ *wordendptr = wordptr + -lookup[offset + 1];

              while (wordptr < wordendptr)
                {
                  register const char *s = wordptr->rwd;

                  if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
                    return wordptr;
                  wordptr++;
                }
            }
        }
    }
  return 0;
}
