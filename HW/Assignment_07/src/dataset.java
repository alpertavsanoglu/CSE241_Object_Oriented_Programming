
public class dataset {

    public dataset(){
        //Initializing the values
        filesize=0;
        playersize=0;
        viewersize=0;
        filearray = new file[0];  
        playerarray  = new player[0];
        viewerarray = new viewer[0];        
      
    }
    public void add(file obj)
    {
        //Increasing the array size by creating a temporary file array and using it
        file temp[] = new file[filesize+1];
        for(int i=0;i<filesize;i++)
        {
            temp[i]=filearray[i];
        }
        temp[filesize]=obj;
        filearray=temp;
        filesize++;
        //Deciding which type to update
        if( obj instanceof playable    ) update_players();
        if( obj instanceof non_playable) update_viewers();
    }
    public void register(player obj)
    {
        //Overloaded function,takes player object as argument
        //Adding a new object to playerarray
        player temp[] = new player[playersize+1];
        for(int i=0;i<playersize;i++)
        {
            temp[i]=playerarray[i];
        }
        temp[playersize]=obj;
        playerarray=temp;
        playersize++; 
        update_players();       //Updating the new added item

    }
    public void register(viewer obj)
    {
        //Overloaded function,takes viewer object as argument
        //Adding a new object to viewerarray
        viewer temp[] = new viewer[viewersize+1];
        for(int i=0;i<viewersize;i++)
        {
            temp[i]=viewerarray[i];
        }
        temp[viewersize]=obj;
        viewerarray=temp;
        viewersize++;
        update_viewers();       
        
    }

    public void remove_observer(player obj)
    {
        //Overloaded function,takes player object as argument
        //Deletes an object from playerarray by using temporary array
        player temp[] = new player[playersize--];
        for(int i=0,j=0;i<=playersize;i++)
        {
            if(obj!=playerarray[i])
            temp[j++]=playerarray[i];
        }
        playerarray=temp;
        update_players();
    }
    public void remove_observer(viewer obj)
    {
        viewer temp[] = new viewer[viewersize--];
        for(int i=0,j=0;i<=viewersize;i++)
        {
            if(obj!=viewerarray[i])
            temp[j++]=viewerarray[i];
        }
        viewerarray=temp;
        update_viewers();
    }
    public void remove(playable obj)
    {
        //Removing a playable object from dataset,updating players
        file temp[] = new file[filesize--];
        for(int i=0,j=0;i<=filesize;i++)
        {
            if(obj!=filearray[i])
            temp[j++]=filearray[i];
        }
        filearray=temp;
        update_players();
       
    }
    public void remove(non_playable obj)
    {
        file temp[] = new file[filesize--];
        for(int i=0,j=0;i<=filesize;i++)
        {
            if(obj!=filearray[i])
            temp[j++]=filearray[i];
        }
        filearray=temp;
        update_viewers();
       
    }

    public void update_players()
    {
         //Instead of designing another function for every scenario
        //Updating every player's playlist on dataset
        file x[] = new file[filesize];
        int count=0;
        //Creating a playable only array and updating the playlists by it
        for(int i=0;i<filesize;i++)
        {
            if(filearray[i] instanceof playable)
            {
                x[count]=filearray[i];
                count++;
            }       

        }

        for(int j=0;j<playersize;j++){
            //Clearing every playlist in dataset to update later
            playerarray[j].cleararray();
            for(int i=0;i<count;i++){       
                playerarray[j].add_to_playlist(x[i]);


        }
        }

    }
    public void update_viewers()
    {
        file T[] = new file[filesize];
        int count=0;
        for(int i=0;i<filesize;i++)
        {
            if(filearray[i] instanceof non_playable)
            {
                T[count]=filearray[i];
                count++;
            }       

        }
        for(int j=0;j<viewersize;j++){
            viewerarray[j].cleararray();
            for(int i=0;i<count;i++){       
                viewerarray[j].add_to_playlist(T[i]);

        }
        }
    }

    private file filearray[];
    private player playerarray[];
    private viewer viewerarray[];
    private int filesize;
    private int playersize;
    private int viewersize;
}
