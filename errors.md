

## Libft

### utils

#### get_curent_time

- Failed fetching current time \\
    - (errno)



### strr_utils

ft_split, split_by_char:
- Failed to split string "<str>" using delimiter `<c>` \\

    - String passed is NULL

    - (errno)

    - Failed to populate array of string

        - Failed to crop string "<str>" using delimiter `<c>`

ft_strrdup:
- Failed to duplicate array of strings

    - String passed is NULL

    - (errno)

    - Failed to duplicate string //ft_strdup

strr_add:
- Failed to append string to array of strings

    - string passed is NULL

    - (errno)

    - Failed to duplicate string //ft_strdup

    - Failed to duplicate string //ft_strdup

### str_utils


dfreejoin, freejoin, str_join, ft_strjoin_all, ft_strjoin_gnl:
- Failed to join strings

ft_strdup, ft_strndup, ft_strndup_gnl:
- Failed to duplicate string

ft_strtrim:
- Failed to trim string

ft_substr:
- Failed to sub string


### io

#### gnl


- Could not get next line

    - Incorrect BUFFER_SIZE or wrong fd

    - (errno)



### data_structs


#### vector

set_vector_size:

- Could not resize vector

vector_add:

- Could not add element to vector

vector_relloc:

- Could not realloc vector


//TODO: list and dlist


### alloc


ft_calloc:

- Invalid calloc size

- (errno)

ft_realloc:

- Could not realloc <old_size> to <size> at adress <pnt>


