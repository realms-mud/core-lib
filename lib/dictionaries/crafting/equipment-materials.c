//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/crafting/core.c";

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setCraftingMaterial(object item, string materialClass,
    string material, string component)
{
    mapping materialSelections = item->query("crafting materials");
    string primaryComponent = item->query("primary component");

    if (!materialSelections)
    {
        materialSelections = ([]);
    }

    if (!component)
    {
        if (!member(materialSelections, materialClass))
        {
            materialSelections[materialClass] = material;
        }
    }
    else
    {
        if (!member(materialSelections, component))
        {
            materialSelections[component] = ([]);
        }
        materialSelections[component][materialClass] = material;
    }

    object materialsDictionary = getDictionary("materials");

    if ((component == primaryComponent) && 
        (materialsDictionary->getMaterialTypeForMaterial(item->query("material")) == 
        materialsDictionary->getMaterialTypeForMaterial(material)))
    {
        item->set("material", material);
        item->set("primary crafting material", material);

        item->set("crafting experience", to_float(
            materialsDictionary->getBlueprintModifier(item, "base experience") *
            (member(materials[material], "experience modifier") ?
                materials[material]["experience modifier"] : 1.0)));
    }
        
    item->set("crafting materials", materialSelections);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string addMaterialsToDescription(object item)
{
    string ret = item->query("long");
    mapping craftingMaterials = item->query("crafting materials");

    if (craftingMaterials && mappingp(craftingMaterials))
    {
        foreach(string materialClass in materialClasses)
        {
            if (member(craftingMaterials, materialClass))
            {
                ret = regreplace(ret, materialClass, craftingMaterials[materialClass], 1);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string replaceDescriptiveText(string text, string type, mapping data)
{
    string ret = text;

    if (member(data, type))
    {
        ret = regreplace(ret, type, data[type], 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getEquipmentMaterials(object item)
{
    string ret = "";

    mapping craftingMaterials = item->query("crafting materials");
    if (craftingMaterials && mappingp(craftingMaterials))
    {
        string *components = sort_array(filter(m_indices(craftingMaterials),
            (: mappingp($2[$1]) :), craftingMaterials), (: $1 > $2 :));

        if (sizeof(components))
        {
            foreach(string component in components)
            {
                string description = craftingMaterials[component]["description"];

                foreach(string materialClass in materialClasses)
                {
                    description = replaceDescriptiveText(description, materialClass,
                        craftingMaterials[component]);
                }
                ret += sprintf("The %s is %s ", component, description);
            }
        }
        if (item->query("primary crafting material"))
        {
            ret = regreplace(ret, "PrimaryMaterial",
                item->query("primary crafting material"), 1);
        }
    }
    return ret;
}
