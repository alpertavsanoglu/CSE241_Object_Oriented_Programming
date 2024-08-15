public class file {
    protected String name;
    protected String info;

    public file()
    {
    }

    public file(String name1,String info1){
        name=name1;
        info=info1;
    }

    public void info()
    {
        System.out.printf("Name : %s \nInfo : %s \n",name,info);
    }


}
