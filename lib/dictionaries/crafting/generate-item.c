//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _generate_items_c
#define _generate_items_c

#include "/lib/dictionaries/crafting/blueprints.c"

/////////////////////////////////////////////////////////////////////////////
private nomask string getRandomCraftingElement(mapping elements, 
    string elementClass)
{
    string *elementList = filter(m_indices(elements),
        (: $2[$1]["class"] == $3 :), elements, elementClass);

    return elementList[random(sizeof(elementList))];
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRandomMaterial(string materialClass, 
    string defaultMaterial)
{
    object materialsDictionary = getDictionary("materials");

    if (!member(MaterialsForClass, materialClass))
    {
        MaterialsForClass[materialClass] = filter(m_indices(materials),
            (: $2[$1]["class"] == $3 :), materials, materialClass);
    }

    if (member(MaterialsForClass[materialClass], defaultMaterial) == -1)
    {
        defaultMaterial = 0;
    }
    return materialsDictionary->getRandomMaterialFromClass(materialClass,
        defaultMaterial);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRandomComponent(string componentClass)
{
    return getRandomCraftingElement(craftingComponents, componentClass);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping generateRandomMaterialList(object blueprint)
{
    mapping ret = ([]);
    mapping neededMaterials = blueprint->query("crafting materials");
    string *componentMaterials = filter(m_indices(neededMaterials),
        (: intp($2[$1]) :), neededMaterials);

    string primaryMaterialClass =
        materials[blueprint->query("default material")]["class"];
    foreach(string componentMaterial in componentMaterials)
    {
        if (neededMaterials[componentMaterial] > 0)
        {
            ret[componentMaterial] = getRandomMaterial(componentMaterial,
                blueprint->query("default material"));

            if (componentMaterial == primaryMaterialClass)
            {
                if (blueprint->query("use default material"))
                {
                    ret[componentMaterial] = blueprint->query("default material");
                }
                blueprint->set("primary crafting material", ret[componentMaterial]);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping generateRandomComponents(object blueprint)
{
    mapping ret = ([]);
    mapping neededMaterials = blueprint->query("crafting materials");

    string *components = filter(m_indices(neededMaterials),
        (: mappingp($2[$1]) :), neededMaterials);

    string primaryMaterialClass =
        materials[blueprint->query("default material")]["class"];

    if (sizeof(components))
    {
        foreach(string component in components)
        {
            string usedComponent = getRandomComponent(component);

            ret[component] = ([
                "type": usedComponent,
                "description": craftingComponents[usedComponent]["description"],
                "value": craftingComponents[usedComponent]["value"],
                "experience modifier": craftingComponents[usedComponent]["experience modifier"],
            ]);

            string *componentMaterials = m_indices(neededMaterials[component]);
            foreach(string componentMaterial in componentMaterials)
            {
                if ((neededMaterials[component][componentMaterial] > 0) ||
                    (member(craftingComponents[usedComponent], "crafting materials") &&
                    member(craftingComponents[usedComponent]["crafting materials"],
                        componentMaterial)))
                {
                    ret[component][componentMaterial] =
                        getRandomMaterial(componentMaterial, blueprint->query("default material"));
 
                    if ((componentMaterial == primaryMaterialClass) &&
                       (blueprint->query("primary component") == component))
                    {
                        if (blueprint->query("use default material"))
                        {
                            ret[component][componentMaterial] = 
                                blueprint->query("default material");
                        }
                        blueprint->set("primary crafting material", 
                            ret[component][componentMaterial]);
                    }
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void getRandomCraftingMaterial(object item, 
    int useDefaultMaterial)
{
    if (!item->query("crafting in progress"))
    {
        object blueprint = getBlueprintFor(item);
        if(blueprint)
        {
            if (useDefaultMaterial)
            {
                blueprint->set("use default material", 1);
            }
            else
            {
                blueprint->unset("use default material");
            }
            mapping materialList = ([]);

            materialList += generateRandomMaterialList(blueprint) +
                generateRandomComponents(blueprint);

            if (item->query("material"))
            {
                item->set("primary crafting material", item->query("material"));
            }
            else if (blueprint->query("primary crafting material"))
            {
                item->set("primary crafting material",
                    blueprint->query("primary crafting material"));
                item->set("material", blueprint->query("primary crafting material"));
            }
            item->set("crafting materials", materialList);
        }
    }
}

#endif
