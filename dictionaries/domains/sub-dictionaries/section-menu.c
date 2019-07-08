//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/domain-layout.c";

#include "/lib/dictionaries/materials/materials.h"

private nomask object materialsDictionary =
    load_object("/lib/dictionaries/materialsDictionary.c");

/////////////////////////////////////////////////////////////////////////////
private nomask int canSelectSection(object user, string option)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping materialsNeededForSection(mapping sectionData,
    string selection)
{
    mapping ret = sectionData[sectionData["selected section"]] + ([]);

    if (selection && member(BuildingComponents, selection) &&
        member(BuildingComponents[selection], "building materials"))
    {
        mapping additionalMaterials =
            BuildingComponents[selection]["building materials"];

        foreach(string material in m_indices(additionalMaterials))
        {
            ret[material] += additionalMaterials[material];
        }
    }
    return filter(ret, (: ret[$1] > 0 :));
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping generateMaterialMenuEntries(mapping sectionData)
{
    mapping ret = ([]);

    string *materialsInSection = sort_array(
        m_indices(sectionData[sectionData["selected section"]]),
        (: $1 > $2 :));

    mapping neededMaterials = materialsNeededForSection(sectionData,
        (member(sectionData, "chosen section") ? 
            sectionData["chosen section"] : 0));

    foreach(string material in materialsInSection)
    {
        ret[to_string(sizeof(ret) + 1)] = ([
            "name": "Select " + generateTitle(material),
            "type": "material",
            "material type": material, 
            "description": "This option assigns workers to the task of "
                "building the selected component.\n",
            "is disabled": !member(neededMaterials, material),
            "selected material": 
                member(sectionData["selected materials"], material) ?
                    sectionData["selected materials"][material] : 0,
            "canShow": 1
        ]); 
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateSectionOptions(mapping output, object user,
    mapping sectionData)
{
    string *sectionOptions = sort_array(filter(m_indices(BuildingComponents),
        (: BuildingComponents[$1]["class"] == $2 :), 
            sectionData["selected section"]),
        (: $1 > $2 :));

    foreach(string option in sectionOptions)
    {
        output[to_string(sizeof(output) + 1)] = ([
            "name": generateTitle(option),
            "type": option,
            "description": "This option assigns workers to the task of "
                "building the selected component.\n",
            "is disabled": canSelectSection(user, option),
            "canShow": 1
        ]); 
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int beginConstructionIsEnabled(mapping sectionData)
{
    int ret = member(sectionData, "chosen section") && 
        member(BuildingComponents, sectionData["chosen section"]) &&
        member(sectionData, "selected materials");

    if (ret)
    {
        mapping neededMaterials = materialsNeededForSection(sectionData,
            sectionData["chosen section"]);

        foreach(string material in m_indices(neededMaterials))
        {
            ret &&= member(sectionData["selected materials"], material);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuildSectionMenu(object user, string location,
    mapping sectionData)
{
    mapping ret = ([]);

    if(mappingp(sectionData) && member(sectionData, "selected section"))
    {
        ret = generateMaterialMenuEntries(sectionData);
        generateSectionOptions(ret, user, sectionData);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getMaterialsOfTypeOnHand(string type, object user,
    mapping sectionData, mapping materialsToBeUsed)
{
    mapping ret = ([]);

    object *inventory = filter(deep_inventory(user),
        (: ((member(inherit_list($1), "lib/items/material.c") > -1) &&
            (member($2, $1->query("class")) > -1)) :), 
            materialsDictionary->getTypes(type, user));

    if (sizeof(inventory))
    {
        foreach(object item in inventory)
        {
            string material = item->query("blueprint");
            if (!member(ret, material))
            {
                ret[material] = 0;
            }
            ret[material] += item->query("quantity");
            if (member(materialsToBeUsed, material))
            {
                ret[material] -= materialsToBeUsed[material];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getMaterialsOfType(string type, object user, 
    mapping sectionData)
{
    mapping ret = ([]);

    mapping materialsToBeUsed = materialsNeededForSection(sectionData,
        (member(sectionData, "chosen section") ?
            sectionData["chosen section"] : 0));

    mapping materialsOnHand = getMaterialsOfTypeOnHand(type, user, 
        sectionData, materialsToBeUsed);

    string *materialsOfType = sort_array(filter(m_indices(materials),
        (: (member($2, materials[$1]["class"]) > -1) :), 
        materialsDictionary->getTypes(type, user)),
        (: $1 > $2 :));

    if(sizeof(materialsOfType))
    {
        int menuItem = 1;

        object materialDictionary = 
            load_object("/lib/dictionaries/materialsDictionary.c");

        foreach(string material in materialsOfType)
        {
            int hasMaterials = (member(materialsOnHand, material) &&
                (materialsOnHand[material] >= materialsToBeUsed[type]));

            object blueprintObj = clone_object("/lib/items/craftingBlueprint.c");
            if (sizeof(materials) && member(materials, material))
            {
                blueprintObj->set("blueprint data", materials[material]);
                blueprintObj->set("blueprint", material);
            }

            int prerequisites = blueprintObj->checkPrerequisites(user) &&
                blueprintObj->checkResearch(user);
            destruct(blueprintObj);

            string name = capitalize(material);
            if (sizeof(name) > 20)
            {
                name = name[0..16] + "...";
            }
            ret[to_string(menuItem)] = ([
                "name": name,
                "type": material,
                "description": sprintf("This options selects %s as your %s "
                    "building material.", material, type),
                "has materials": hasMaterials,
                "prerequisites met": prerequisites,
                "canShow": (hasMaterials && prerequisites)
            ]);
            menuItem++;
        }
    }

    ret[to_string(sizeof(ret) + 1)] = ([
        "name":"Exit Material Menu",
        "type": "exit",
        "description": "This option lets you exit the material "
            "selection menu.\n",
        "canShow": 1
    ]);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *displaySectionData(object user, mapping sections,
    string colorConfiguration, string charset)
{
    string *ret = ({ configuration->decorate("Building Sections:",
        "heading", "player domains", colorConfiguration)
        });

    string selectedSection = sections["selected section"];
    string *sectionList = sort_array(m_indices(sections), (: $1 > $2 :));

    sectionList -= ({ "name", "selected section", "selected materials",
        "chosen section" });

    foreach(string section in sectionList)
    {
        string currentSection = member(sections, "chosen section") ?
            configuration->decorate(sections["chosen section"],
                "selected", "player domains", colorConfiguration) :
            configuration->decorate("<Make Selection>",
                "selection needed", "player domains", colorConfiguration);

        string sectionInfo = (section == selectedSection) ? currentSection :
            configuration->decorate("<Not Selected Yet>",
                "not selected yet", "player domains", colorConfiguration);

        string entry = "    " +
            configuration->decorate(generateTitle(section),
                "value", "player domains", colorConfiguration) + ": " +
                (member(sections[section], "selection") ?
                    configuration->decorate(
                        generateTitle(sections[section]["selection"]["name"]),
                        "selected", "player domains", colorConfiguration) :
                    sectionInfo);

        ret += ({ entry });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBuildSectionInfo(object user, mapping componentData)
{
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();

    return generateBuildInfo(
        displayLayout(componentData["name"], colorConfiguration, charset),
        displaySectionData(user, 
            componentData + ([]),
            colorConfiguration, charset));
}
