#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include <vector>
#include <memory>
class hittable_list:public hittable
{
public:
    hittable_list(){};
    hittable_list(std::shared_ptr<hittable>object){add(object);}

    void clear(){objects.clear();}
    void add(std::shared_ptr<hittable>object){objects.push_back(object);}
    virtual bool hit(const ray& r,double t_min,double t_max,hit_record&rec)const;



public:
    std::vector<std::shared_ptr<hittable>> objects;
};
bool hittable_list::hit(const ray& r,double t_min,double t_max,hit_record& rec) const{
    hit_record temp_record;
    bool hit_anything=false;
    double closet_so_far=t_max;
    for (const auto& object:objects)
    {
        if (object->hit(r,t_min,closet_so_far,temp_record))
        {
            hit_anything=true;
            closet_so_far=temp_record.t;
            rec=temp_record;
        }
        
    }
    return hit_anything;

}


#endif