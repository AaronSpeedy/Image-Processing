class Image
{
    public:
    std::vector<std::vector<int>> pixels;
    int width;
    int height;
    std::string name; 
    void Image(std::string namep, int sizeXp, int sizeYp)
    {
        name = namep;
        width = sizeXp;
        height = sizeYp;
        for(int i = 0; i < sizeX * sizeX; i++)
        {
            pixels[i][0].push_back(0);
            pixels[i][1].push_back(0);
            pixels[i][2].push_back(0);
        }
    }
    void editPixel(int X, int Y, int r, int g, int b)
    {
        pixels[X + width*Y][0] = r;
        pixels[X + width*Y][1] = g;
        pixels[X + width*Y][2] = b;
    }
    void ~Image()
    {
        ofstream imageFile(name + ".ppm");
        imageFile << "P3\n";
        imageFile << width << " " << height << "\n";
        for(int i = 0; i < pixels.size(); i++)
        {
            imageFile << pixels[i][0] << " ";
            imageFile << pixels[i][1] << " ";
            imageFile << pixels[i][2] << " ";
        }
        file.close();
    }
}