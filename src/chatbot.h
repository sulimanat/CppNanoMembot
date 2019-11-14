#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>
#include <memory>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot &source){
    
    _image=source._image; // avatar image

    _currentNode=source._currentNode;
    _rootNode=source._rootNode;
    _chatLogic=source._chatLogic;
    
    };
    
    ChatBot &operator=(const ChatBot &source){
    std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;
//        	 delete _image; // avatar image
//          delete _currentNode;
//          delete _rootNode;
//          delete _chatLogic;
         _image = new wxBitmap();
        _image = source._image;
//         _currentNode=new GraphNode(source._currentNode->GetID());
         _currentNode=source._currentNode;
//          _rootNode=new GraphNode(source._rootNode->GetID());
    	_rootNode=source._rootNode;
//         _chatLogic=new ChatLogic();
    	_chatLogic=source._chatLogic;
        return *this;
    }
    
    ChatBot(ChatBot &&source) {
    
    std::cout << "MOVING content of instance " << &source << " to instance " << this << std::endl;
     
        _image = source._image;
        _currentNode=source._currentNode;
    	_rootNode=source._rootNode;
    	_chatLogic=source._chatLogic;

//         delete source._image;
//         delete source._currentNode;
//     	delete source._rootNode;
//     	delete source._chatLogic;
	
    }
    ChatBot &operator=(ChatBot &&source){
    
    std::cout << "MOVING (assign) content of instance " << &source << " to instance " << this << std::endl;
     
     	 if (this == &source)
            return *this;
        
//         delete _image;
        
        _image = source._image;
        _currentNode=source._currentNode;
    	_rootNode=source._rootNode;
    	_chatLogic=source._chatLogic;
		
         source._image=nullptr;
         source._currentNode=nullptr;
    	 source._rootNode=nullptr;
    	 source._chatLogic=nullptr;
    
		return *this;

    }
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode* rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */