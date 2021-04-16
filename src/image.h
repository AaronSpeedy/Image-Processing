class Image
{
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
        ofstream file(name + ".ppm");
        file << "P3\n";
        file << width << " " << height << "\n";
        for(int i = 0; i < pixels.size(); i++)
        {
            file << pixels[i][0] << " ";
            file << pixels[i][1] << " ";
            file << pixels[i][2] << " ";
        }
        file.close();
    }
}