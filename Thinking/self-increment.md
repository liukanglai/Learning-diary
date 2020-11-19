# talk about the a[++i]

such as:

        while(i < strlen(a)){
            if(a[++i]) a[i] = 0;
        }
        
- if i = strlen(a) - 1, then a[++j] is wrong.
- and if use a[i++], the a[i] will be wrong.

so the best way is to use i++ out of the a[]...
