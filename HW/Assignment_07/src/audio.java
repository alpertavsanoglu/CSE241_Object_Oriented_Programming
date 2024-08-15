public class audio extends file implements playable,non_visual {
    private double duration;

    public audio()
    {
    }
    public audio(audio obj)
    {
        this(obj.name,obj.duration,obj.info);
    }
    public audio(String name1, double dur, String info) {
        super(name1, info);
        duration = dur;
    }
    public double get_duration()
    {
        return duration;
    }
    public void info(){
        super.info();
        System.out.printf("Duration : %.1f min\n\n",get_duration());
    }
   
}
