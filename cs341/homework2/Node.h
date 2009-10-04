// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #2

#ifndef NODE_H
#define NODE_H

namespace lorber_homework2
{

  class Node {
  public:

    typedef double value_type;
 
    /// Constructor
    Node(const value_type& data, Node* link);

    void set_data(const value_type& data);

    void set_link(Node* link);

    value_type data() const;

    Node* link();

    const Node* link() const;
    
  protected:
  private:
    value_type _user_data;
    Node* _link;

  };
  
}

#endif // #ifndef NODE_H
