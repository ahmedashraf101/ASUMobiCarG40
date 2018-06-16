class Project{
  // @string mode
  private:
    char* _mode; 
   public:
   /**
    *@param mode string
    *initially  assign _mode to @param mode
   */ 
   
    Project(char * mode){
      this->_mode = mode;
    }
    /**
     * setMode prototype
    * @param mode string
    */
    void setMode(char * mode);
  };
  void  Project::setMode(char * mode){
      _mode = mode;
      Serial.print(*(_mode));
    }

    //Initialize Project
Project project("goo");
void setup(){
  //Mode setting
  project.setMode("Mode");

  
}

void loop(){
  

  
}


