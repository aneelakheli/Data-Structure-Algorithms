## Structure

A structure is a collection of one or more variables, possibly of different types, grouped together under a single name. An array is a data structure in which all the members are of the same data type. Structure is another data structure in which the individual elements can differ in type. Thus, a single structure might contain integer elements, floating-point elements and character elements. The individual structure elements are referred to as members.

```
struct structure_name
{
member 1;
member 2;
...........
member n;
};
```

``` 
**struct** Student{
    **char** name[10];
    **int** roll;
    **char** sec;
    **float** marks;
};
```

## Structure variable declaration:
    **struct** Student s1,s2,s3;


## Accessing members of a structure:
There are two types of operators to access members of a structure. Which are:
- Member operator (dot operator or period operator (.))
-  Structure pointer operator (->).


## Unions:
Both **structure** and **unions** are used to group a number of different variables together. Syntactically both structure and unions are exactly same. The main difference between them is in storage. In structures, each member has its own memory location but all members of union use the same memory location which is equal to the greatest member’s size.

### Declaration of union:
The general syntax for declaring a union is:
```
    union union_name{
        data_type member_1;
        data_type member_2;
        data_type member_3;
    }