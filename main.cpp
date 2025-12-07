#include <iostream>
#include "Planar.h"
#include "Point.h"
#include "Fanction.h"

int main()
{
    size_t s = 0;
    size_t capusity = 20;

    Planar** pls = new Planar * [capusity];

    while (std::cin)
    {
        Planar* pl = nullptr;

        try
        {
            pl = make(std::cin);

            if (pl == nullptr)
                break;

            if (s == capusity)
            {
                Planar** epls = new Planar * [capusity * 2];

                for (size_t i = 0; i < s; ++i)
                {
                    epls[i] = pls[i];
                }

                delete[] pls;
                pls = epls;
                capusity *= 2;
            }

            pls[s++] = pl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error creating object: " << e.what() << "\n";
            delete pl;
            free_planars(pls, s);
            delete[] pls;
            return 1;
        }
    }

    if (s == 0)
    {
        std::cout << "No objects found\n";
        delete[] pls;
        return 0;
    }

    Planar** ml = most_left(pls, s);

    if (ml == pls + s)
    {
        std::cout << "Net fuond";
        free_planars(pls, s);
        delete[] pls;
        return 0;
    }

    std::cout << "New  most left" << "\n";
    draw(*ml);

    Planar** max_a = max_area(pls, s);

    if (max_a != nullptr)
    {
        std::cout << "New max area" << "\n";
        draw(*max_a);
    }

    Planar** max_pair = max_frame_intersects(pls, s);

    if (max_pair != nullptr)
    {
        std::cout << "New  max frame intersects" << "\n";
        draw(max_pair[0]);
        draw(max_pair[1]);

        Frame f1 = max_pair[0]->frame();
        Frame f2 = max_pair[1]->frame();
        int intersection = f1.intersection_area(f2);
        std::cout << intersection << "\n";

        delete[] max_pair;
    }

    free_planars(pls, s);
    delete[] pls;

    return 0;
}
