#include <stdio.h>

int main()
{
    /*
        You can pack information into the bits of a byte if
        you do not need to use the entire byte to represent data

            - flags that are used for a boolean true of false
            condition can be represented in a single bit on a
            computer
            - You can use a unsigned int/long variable to hold
            the same information
            - used to conserve memory space
            - flags that are used for a boolean true or false condition
            can be represented in a single bit on a computer
    */

    /*
        Example: You want to pack five data values into a word
        because you have to maintain a very large table of these
        values in memory
            - assume that 3 of these data values are flags (f1, f2 and f3)
            - the 4th values is an int called "type", ranges 1 to 255
            - the final value is an int called "index" ranges 0 to 100,000

        storing values of flags f1, f2 and f3 only requires 3 bits
        storeing value of int "type" requires 8 bits
        storing values of the int "index" requires 18 bits
        total storage needed for 5 data vlues is 29 bits

        | 000 | 0 | 0 | 0 | 00000000 | 000000000000000000 |
        |Unused|f1| f2| f3|  type    |       index        |
    */

    unsigned int packed_data = 0;

    /*
        set the "type" field of the packed_data to 7
        shift the value 7 to the left the appropriate number of
        places and then OR it into packed_data
    */
    packed_data |= 7 << 18;

    /*
       set the "type" field to the value n, where n is between 0 and 255
       to ensure n is between 0 - 255, you can AND it with 0xff
       before it's shifted
    */
    unsigned int n = 254;   // between 0 and 255
    printf("%d\n", n & 0xff);

    n = 256;   // more then 255
    printf("%d\n", n & 0xff);

    packed_data |= (n & 0xff) << 18;

    /*
        the statement on the previous comments only works if "type"
        field is 0
        -   to zero out the "type" field, you need to first AND it with
        a value (bitmsak) that consists of 0s in the 8 bit locations
        of the type field and 1s everywhere else
    */
    packed_data &= 0xfc03ffff;

    /*
        to save yourself having to calculate the bitmask and also to
        make the operation independent of the size of an int
        -   You could instead use the blow statement to set the "type"
        field to zero
    */
    packed_data &= ~(0xff << 18);

    /*
       combining the statement describe previously, you can set the type
       field of packed_data to the value contained in the 8 low-order
       bits of n
    */
    packed_data = (packed_data & ~(0xff << 18)) | ((n & 0xff) << 18);

    /*
       extracking the value
        - the field can be shifted into the low-order bits of
        the word and then AND'ed with a mask of the appropriate bit
        length
    */
    unsigned int n = 0;

    n = (packed_data >> 18) & 0xff;

    return 0;
}
