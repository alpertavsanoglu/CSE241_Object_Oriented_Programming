public class video extends file implements playable,visual{
    private double duration;
    private int dimension;
    public video(){}
    public video(video obj)
    {
        this(obj.name,obj.duration,obj.dimension,obj.info);
    }
    public video(String name1, double dur, int dim,String info) {
        super(name1, info);
        duration = dur;
        dimension=dim;
    }
    public double get_duration()
    {
        return duration;
    }
    public int get_dimension()
    {
        return dimension;
    }
    public void info(){
        super.info();
        System.out.printf("Duration : %.1f min\n",get_duration());
        System.out.printf("Dimension : %d\n\n",get_dimension());

    }
}
