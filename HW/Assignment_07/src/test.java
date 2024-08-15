
public class test {

    public static void main(String[] args) {

        dataset ds = new dataset();
        player p1 = new player();
        player p2 = new player();
        viewer v1 = new viewer();
        player p3 = new player();
        viewer v2 = new viewer();

        ds.add(new video("video1", 57.5, 3, "insanazor"));
        ds.add(new audio("audio1", 150.0, "siuuu"));
        ds.add(new video("video2", 170.4, 3, "bibob"));
        ds.add(new audio("audio2", 21.0, "pin250"));

        ds.add(new image("imagename1", 3, "other info1"));
        ds.add(new image("imagename2", 2, "other info2"));
        ds.add(new image("imagename3", 2, "other info3"));

        ds.add(new text("textname1", "other info1"));
        ds.add(new text("textname2", "other info2"));

        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);
        //Currently_playing will start from first entry
        System.out.println("AA.INFO START");
        playable aa=p1.currently_playing();
        aa.info();
        //Moving v1 current index to textname2
        v1.next("text");
        v1.next("text");
        non_playable np = v1.currently_viewing();
        System.out.println(" NP.INFO START ");
        np.info();

        //Moving p1 current index to audio2
        p1.next("audio");
        p1.next("audio");
        System.out.println(" PX.INFO START ");
        playable px = p1.currently_playing();
        px.info();


        //Removing audio2 and printing p1 
        ds.remove(px);
        System.out.println("PX REMOVED--P1 SHOWLIST");
        p1.show_list();

        //Removing p2 from dataset-Stops taking updates
        //So it wont have audio3 on its list
        ds.remove_observer(p2);
        ds.add(new audio("audio3", 14.7, "added after removing p2"));
        System.out.println("P2 OBSERVER REMOVED--P2 SHOWLIST ");
        p2.show_list();

        //Didn't register p3 to dataset so its empty
        //Showlist will give error and currentlyplaying will show a dummy object
        System.out.println("P3-EMPTY SHOWLIST");
        p3.show_list();
        System.out.println("P3-EMPTY CURRENTLY PLAYING");
        playable dd = p3.currently_playing();
        dd.info();

        //audio2 deleted so it automatically moves to audio3
        //next will give an error and stay at the same index
        p1.next("audio");
        playable dx = p1.currently_playing();
        dx.info();

        //Removed v2 from taking updates
        //Comparing v2 and v1
        //v2 wont show imagename4 while v1 will
        ds.remove_observer(v2);
        ds.add(new image("imagename4",3,"added after v2 removed"));
        System.out.println("V2 SHOWLIST AFTER REMOVING FROM DATASET");
        v2.show_list();
        System.out.println("V1 SHOWLIST WITH UPDATE");
        v1.show_list();
    }

}
