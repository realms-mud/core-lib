//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "racial");
    addSpecification("name", "Half Elf");
    addSpecification("description", "High elves of this subrace are not "
        "half-elven in the 'half elf, half human' sense. They are the "
        "descendants of the union of high elves, humans, and the gods "
        "themselves. It is said that Aronath - son of Aradran, "
        "the high king of the elves and Eadwyn, a goddess of hope and the mistress "
        "of desires - fell in love with Maerwena, the daughter of the human king of "
        "Tirnen. One son, Arahir, chose Morwen, a human, as his wife. The "
        "other, Elehir, chose Aelndwyn, the high-elven Lady of the Gahldrim "
        "as his wife. From that union come all within this tree. "
        "In appearance, they typically have grey or blue eyes and black hair, much. "
        "like their forbears did. The darkness surrounding the high elves "
        "lays particularly strong among the half elves - much misery and "
        "woe has befallen and continues to hound this line.");
    addSpecification("root", "high elf");
    addSpecification("opposing root", "dwarf");
    addSpecification("opinion", 20);
    addSpecification("opposing opinion", 5);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus magical essence", 5);
    addSpecification("bonus heal hit points", 2);
    addSpecification("bonus heal spell points", 2);
    addSpecification("bonus heal stamina", 2);
    addSpecification("bonus defense", 1);
    addSpecification("bonus damage", 1);
    addSpecification("bonus attack", 1);
}
