//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _random_material_c
#define _random_material_c

#include "/lib/services/materials/components/core.c"

/////////////////////////////////////////////////////////////////////////////
private nomask string *getWeightedMaterial(string material)
{
    string *weightedMaterials = ({});
    int numToAdd = 0;
    switch (materials[material]["scarcity"])
    {
        case "common":
        {
            numToAdd = 8;
            break;
        }
        case "uncommon":
        {
            numToAdd = 3;
            break;
        }
        case "rare":
        {
            numToAdd = 1;
            break;
        }
        case "very rare":
        {
            numToAdd = !random(3);
            break;
        }
    }

    for (int i = 0; i < numToAdd; i++)
    {
        weightedMaterials += ({ material });
    }
    return weightedMaterials;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string getRandomMaterialFromClass(string materialClass,
    string defaultMaterial)
{
    if (!member(WeightedMaterials, materialClass))
    {
        int useCrystals = materialClass == "metal";

        string *options = filter(m_indices(materials),
            (: (($2[$1]["class"] == $3) ||
            ($4 && !random(10) && ($2[$1]["class"] == "crystal"))) :),
            materials, materialClass, useCrystals);

        WeightedMaterials[materialClass] = ({});

        if (defaultMaterial)
        {
            for (int i = 0; i < 100; i++)
            {
                WeightedMaterials[materialClass] += ({ defaultMaterial });
            }
        }

        if (sizeof(options))
        {
            foreach(string material in options)
            {
                WeightedMaterials[materialClass] += getWeightedMaterial(material);
            }
        }
    }

    return sizeof(WeightedMaterials[materialClass]) ?
        WeightedMaterials[materialClass][
            random(sizeof(WeightedMaterials[materialClass]))] : "error";
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getRandomMaterial(object item)
{
    string defaultMaterial = item->query("material");
    string ret = defaultMaterial;
    if (member(materials, defaultMaterial))
    {
        string materialClass = materials[defaultMaterial]["class"];
        ret = getRandomMaterialFromClass(materialClass, defaultMaterial);
    }
    return ret;
}

#endif
