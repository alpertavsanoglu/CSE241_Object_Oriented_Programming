import java.util.ArrayList;

public class player extends observer {
    public player()
    {
        index = 0;
        playlist = new ArrayList<file>();
    }
   
    public void add_to_playlist(file obj)
    {
        //If the object is playable type,add it,if not give error
        if(obj instanceof playable)
        playlist.add(obj);
        else
        {
            System.out.println("Attempt to ad non-playable file to player class");
        }
        
    }
    public void cleararray()
    {
        playlist.clear();
    }
   
    public void show_list()
    {
        //If array is empty,give error,else print one-by-one
        if(playlist.size()==0)
        {
            System.out.println("No item found");
            return;
        }
        for(int i=0;i<playlist.size();i++)
        {
            playlist.get(i).info();
           
        }
    }
    public playable currently_playing()
    {
        //If its not empty,return the object in the index;
        if(playlist.size() != 0 && index < playlist.size())
        {   
            return (playable)playlist.get(index);

        }
        System.out.println("No item found");
        return new audio("dummy",0.0,"dummy");   
    }
        public void next(String type)
        {
            //Updating the index to keep track of which item is currently_playing
            if(type=="audio")
            {
                for(int i = index+1;i<playlist.size();i++)
                {
                    if(playlist.get(i) instanceof audio)
                    {    
                    index=i;
                    return;
                    }
                }
            }
            if(type=="video")
            {
                for(int i = index+1;i<playlist.size();i++)
                {
                    if(playlist.get(i) instanceof video)  {
                        index=i;
                        return;
                        }
                }
            }
            //If required item cannot be found,give an error and stay at the same index
            System.out.println("No next data found for the given type");

        }
        public void previous(String type)
        {
            int i=index-1;
            if(type=="audio")
            {
              while(i>=0)
              {
                if(playlist.get(i) instanceof audio)
                { 
                    index=i;
                    i=-1;
                    return;
                }
                i--;
              }
              return;
            }
            if(type=="video")
            {
                while(i>=0)
              {
                if(playlist.get(i) instanceof video)
                { 
                    index=i;
                    i=-1;
                    return;
                }
                i--;
              }
            }
            System.out.println("No previous data found for the given type");
        }





    private ArrayList<file> playlist;
    private int index;
}
