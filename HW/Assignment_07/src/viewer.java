import java.util.*;
public class viewer extends observer {
    public viewer()
    {
        index = 0;
        playlist = new ArrayList<file>();
    }
   
    public void add_to_playlist(file obj)
    {
        if(obj instanceof non_playable){
        playlist.add(obj);}
        else
        {
            System.out.println("Attempt to ad playable file to viewer class");
        }

    }
    public void cleararray()
    {
        playlist.clear();
    }
   
    public void show_list()
    {
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
    public non_playable currently_viewing()
    {
        if(playlist.size() != 0 && index<playlist.size())
        {   
            return (non_playable)playlist.get(index);

        }
        System.out.println("No item found");
        return new image("dummy",0,"dummy");   
    }
        public void next(String type)
        {
            if(type=="image")
            {
                for(int i = index+1;i<playlist.size();i++)
                {
                    if(playlist.get(i) instanceof image)  { 
                        index=i;
                        return;
                        }
                }
            }
            if(type=="text")
            {
                for(int i = index+1;i<playlist.size();i++)
                {
                    if(playlist.get(i) instanceof text)  { 
                        index=i;
                        return;
                        }
                }
            }
            System.out.println("No next data found for the given type");

        }
        public void previous(String type)
        {
            int i=index-1;
            if(type=="image")
            {
              while(i>=0)
              {
                if(playlist.get(i) instanceof image)
                { 
                    index=i;
                    i=-1;
                    return;
                }
                i--;
              }
              return;
            }
            if(type=="text")
            {
                while(i>=0)
              {
                if(playlist.get(i) instanceof text)
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
