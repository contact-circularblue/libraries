 class  myassignedWaypointClass 
{
    
  public:
    myassignedWaypointClass(float pLong= 0, float pLat= 0)
      {
        fLong = pLong;
        fLat= pLat;
      }
      
    float getLat(void) {return fLat;}
    float getLong(void) {return fLong;}

  private:
    float fLong, fLat;
      
  
};  //myassignedWaypoint



