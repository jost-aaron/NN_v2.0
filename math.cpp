#include "math.h"

#define matrix_index(row,collum) (collum+row*size_x)


// // Vector Slice function
// std::vector<int> vec_slice(const std::vector<int>& v, unsigned int start=0, unsigned int end=-1) {
//     unsigned int oldlen = v.size();
//     unsigned int newlen;
//
//     if (end == -1 or end >= oldlen){
//         newlen = oldlen-start;
//     } else {
//         newlen = end-start;
//     }
//
//     std::vector<int> nv(newlen);
//
//     for (unsigned int i=0; i<newlen; i++) {
//         nv[i] = v[start+i];
//     }      static_cast<char>(data_structure[bindex]);
//
//     return nv;
// }


// template data type to allow for any data type


template <class vector_data> void print_vector(std::vector<vector_data> vec_in){
  std::cout << "[";

  for (unsigned int index=0;index < vec_in.size();index++){
    if (index != 0){
      std::cout << " , ";
    }
    std::cout << vec_in[index];
  }

  std::cout << "]\n\n";
}



// Matrix class
template <class data_type> class matrix {
private:

  unsigned int size_x;
  unsigned int size_y;
  std::vector<data_type> data_structure;


  // Private multiply by vector
  void __multiply_vector(std::vector<data_type>* vector_in){

    // Verify all of the dimensio.hns are correct in the
    __verify_multiply_dims(vector_in);

    // Itterate though all of the rows and collums
    for (unsigned int row = 0; row < size_y; row++) {
      for (unsigned int collum = 0; collum < size_x; collum++) {

        // Calculate the position of the value we are interested in
        unsigned int index = matrix_index(row,collum);

        // multiply the stuff
        data_structure[index] = data_structure[index] * (*vector_in)[collum];
      }
    }

  }

  // Verify the dimentsions of the vector you are mutiplying by the matrix
  void __verify_multiply_dims(std::vector<data_type> *vec_in){
    // Make sure this multiplication is legal
    if (vec_in->size() != size_x){
      std::cout << "ERROR: tried to multiply matrix with incorrect length or dimensions!\n";
      std::cout << "       matrix dimensions: " << size_x << "x" << size_y << "\n";
      std::cout << "       vector dimensions: " << vec_in->size() << "\n";
      std::cout << "       expected length: " << size_x << "\n";
      exit(1);
    }
  }

  std::vector<data_type> __sum_collums(){

    // sum the rows of the matrix
    // Itterate though all of the data
    // We initalize collum to 1 so we skip the first collum
    for (unsigned int row=0;row<size_x;row++){
      for (unsigned int collum=1;collum<size_y;collum++){
        // we are adding all of the values to the value in the first collum
        data_structure[matrix_index(row,0)] += data_structure[matrix_index(row,collum)];
      }
    }

    // return the first value of  each row
    // create a storage variable
    std::vector<data_type> vec_out(size_y);

    // fill the storage variable
    for (unsigned int row=0;row<size_y;row++){
      vec_out[row] = data_structure[matrix_index(row,0)];
    }

    return vec_out;



  }

public:
  // constructor definition for no input data defaults to 1
  matrix (unsigned int input_x,unsigned int input_y){
    size_x = input_x;
    size_y = input_y;
    data_structure.resize(input_x*input_y,(data_type)1);
  }

  // constructor definition with input data
  matrix(unsigned int input_x,unsigned int input_y,std::vector<data_type>* vec_in){
    // verify that this matrix can be constructed in the first place
    if (input_x*input_y != vec_in->size()){
      std::cout << "ERROR: Tried to construct a non symetric matrix!";
      exit(1);
    }

    size_x = input_x;
    size_y = input_y;
    data_structure = *vec_in;

  }


  // For getting the value at an index. returns a pointer
  data_type* access(unsigned int input_row,unsigned int input_collum){
    return *data_structure[matrix_index(input_row,input_collum)];
  }

  // Multiply the matrix by a scaler
  void multiply_scaler(data_type mult_val){
    // Itterate though all of the elements of the matrix
    for (unsigned int index = 0; index < data_structure.size(); index++) {
      data_structure[index] = data_structure[index]*mult_val;
    }

  }



  // Multiply the matrix by a vector and return a new
  matrix<data_type> multiply_vector(std::vector<data_type>* vector_in){

    // Generate a copy of the data we can work with
    //std::vector<data_type> data_copy = data_structure;
    matrix<data_type> data_copy = *this;

    data_copy.__multiply_vector(vector_in);

    return data_copy;
  }



  // Multiply a vector by the matrix then sum the rows
  std::vector<data_type> multiply_vector_dot(std::vector<data_type>* input_vec) {

    // Verify the dimentsions of the matrix
    __verify_multiply_dims(input_vec);

    // multiply the matrix by the vector
    matrix<data_type> multiplied = multiply_vector(input_vec);

    return multiplied.__sum_collums();

  }


// print out the matrix
// FOR DEBUGGING ONLY
  void print(){
    // Itterate though all of the data
    for (unsigned int index = 0; index < data_structure.size(); index++) {
      // Check to see if this is a new row in the matrix
      if ( index % size_x == 0) {
        if (index == 0) {
          printf("|");
        } else{
          printf(" |\n|");
        }
      }

        std::cout << " " << (data_structure[index]);
    }
    printf(" |\n\n" );


  }



};

// Tensor class
//TODO Build tensor class based on matrix class
class tensor {
private:
  /* data */
  unsigned int size_x;
  unsigned int size_y;
  unsigned int size_z;

public:
  tensor (unsigned int input_x, unsigned int input_y, unsigned int input_z);
};
