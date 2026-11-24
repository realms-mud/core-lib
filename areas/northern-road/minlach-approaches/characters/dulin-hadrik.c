//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Dulin Hadrik");
    short("Dulin Hadrik, the chandler's carter");
    description("Dulin is a dwarf with a russet beard braided in "
        "three short tails and dark eyes that crinkle when he smiles. "
        "A pale burn marks the back of his left hand, and his coat "
        "smells faintly of lamp oil, rope tar, and salt. He keeps "
        "his supply lists in a waterproof leather tube.");
    Gender("male");
    Race("dwarf");
    SetUpPersonaOfLevel("farmer", 3);
    addTrait("/lib/instances/traits/personality/honest.c");
    addTrait("/lib/instances/traits/personality/shrewd.c");
    addConversation("/areas/northern-road/minlach-approaches/characters/"
        "dulin-hadrikConversation.c");
}
