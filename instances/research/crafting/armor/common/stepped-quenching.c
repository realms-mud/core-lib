//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Stepped Quenching - Armor");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of stepped quenching metal for use in armor. The metal "
            "is first cooled in a metallic bath - liquified lead or another "
            "metal with an extremely low melting point (at around 200 to 300 "
            "degrees C). After the metal has come to a uniform temperature, "
            "it is then cooled in either a salt or an oil bath. This treatment "
            "results in a crystalline structure in the metal that is extremely "
            "hard and slightly less brittle than traditional quenching.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/armor/common/quenching.c",
            (["type":"research"]));
        addSpecification("limited by", (["crafting type":({ "chainmail",
            "plate armor", "splint armor", "scale armor", "helmet" })]));

        addSpecification("bonus crafting armor class", 1);
    }
}
