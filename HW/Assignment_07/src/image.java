public class image extends file implements non_playable,visual{
    private int dimension;
    public image(String name1, int dim, String info) {
        super(name1, info);
        dimension = dim;
    }

    public void info(){
        super.info();
        System.out.printf("Dimension : %d\n\n",get_dimension());
    }

    public int get_dimension()
    {
        return dimension;
    }
}
