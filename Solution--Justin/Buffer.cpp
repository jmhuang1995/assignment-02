/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Justin Huang <jmhuang1995@gmail.com>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Implements `buffer.h`.
 */

// TODO: `#include`s for system headers, if necessary
#include<iostream>
#include "buffer.h"

// TODO: `#include`s for other local headers, if necessary
using std::cerr;
using std::cout;
// ----------------------------------------------------------------------------

// TODO: implementations for all functions in `class Buffer`

Buffer::Buffer(unsigned int size_x, unsigned int size_y):
size_x(size_x), size_y(size_y)
{
	data_ = new char[size_x * size_y]{};

	
}
/**
* The constructor.
*
* Must initialize `size_x` and `size_y`, and allocate memory for (and
* initialize) `data_`.
*
* Notes:
* - Since `size_x` and `size_y` are constant, they must be initialized
*   in the initialization list, rather than set in the constructor
*   body.
* - You may assume that the dynamic memory allocation succeeds.
*/

Buffer::~Buffer()
{
	delete[] data_;
}
/**
* The destructor.
*
* Must free the memory that the constructor allocated to `data_`.
*/


char Buffer::get(unsigned int x, unsigned int y) const
{
	if (x > size_x - 1 || y > size_y - 1 || x < 0 || y < 0)
	{
		cerr << "ERROR! Buffer get : index out of bounds! \n ";
		exit(1);
	}
	else return data_[y * size_x + x];
}
/**
* Return the character at `data_[ y * size_x + x ]`.
*
* If `x` or `y` is out of bounds, should write
* ```
* "ERROR: `Buffer::get`: index out of bounds\n"
* ```
* to `cerr` and `exit(1)`.
*/

void Buffer::set(unsigned int x, unsigned int y, char c)
{
	
	 if (x > size_x - 1 || y > size_y - 1 || x < 0 || y < 0)
	{
		cerr << "ERROR! Buffer set: index out of bounds! \n"; 
		exit(1);
	}
	else
	{
		data_[y * size_x + x] = c;
	}
}
/**
* Set the character at `data_[ y * size_x + x ]` to `c`.
*
* If `x` or `y` is out of bounds, should write
* ```
* "ERROR: `Buffer::set`: index out of bounds\n"
* ```
* to `cerr` and `exit(1)`.
*/

void Buffer::set(unsigned int pos_x, unsigned int pos_y, std::string s)
{
	int x = pos_x, y = pos_y;
	for (int n = 0;  n < s.length(); n++)
	{
		if (s[n] == '\n')
		{
			y++;
				x = pos_x;
		}
		else
		{
			set(x++, y, s[n]);
		}
	}
}
/**
* Overlay `s` onto `data_`.
*
* For example, if this buffer is representing an array that looks like
* ```
* *******
* *******
* *******
* *******
* *******
* ```
* and we call `set(1, 2, "hello\nworld")`, the buffer's contents
* should now be
* ```
* *******
* *******
* *hello*
* *world*
* *******
* ```
*
* Notes:
* - This function may call the other `set` (which takes a `char` as
*   its last argument), if you like.  In that case, you may leave the
*   index error checking to the other `set`.  Otherwise, you should
*   have checks in this function to make sure you're not putting
*   characters where they don't belong.
* - This function will be useful when implementing the `Shape` class.
* - If you can't think of a way to do this, see
*   `solution---Buffer-set.md`.
*/


void Buffer::draw() const
{
	for (int n = 0; n < size_x * size_y; n++)
	{
		cout << data_[n];
	}
}
/**
* Output the contents of the buffer to `cout`.
*/


void Buffer::clear()
{
	for (int n = 0; n < size_x * size_y; n++)
	{
		data_[n] = ' ';
	}
}
/**
* Set each element `data_` to ' '.
*/
