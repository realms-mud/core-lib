//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Forge Welding - Armor");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of forge welding metal - the act of combining two "
            "disparate metal pieces to form a single body.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/armor/common/annealing.c",
            (["type":"research"]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 3]));
        addPrerequisite("blacksmithing", (["type":"skill", "value" : 5]));
        addPrerequisite("chemistry", (["type":"skill", "value" : 2]));
        addPrerequisite("physics", (["type":"skill", "value" : 2]));

        addSpecification("limited by", (["crafting type":({ "chainmail",
            "plate armor", "splint armor", "scale armor", "helmet" })]));
    }
}
