//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("zombie");
    short("An animated corpse");
    addAlias("animated corpse");
    addAlias("corpse");

    Gender(1);
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 1);
    setUpRandomEquipment(0);
}

/////////////////////////////////////////////////////////////////////////////
public void onDeath(object caller)
{
    printf("%O died - checked by %O\n", caller, this_object());
    if (caller && (program_name(caller) == "lib/tutorial/characters/keeper-of-the-night.c"))
    {
        tell_room(environment(this_object()),
            sprintf("The zombie collapses to the ground, no longer animated.\n"));

        object *inventory = all_inventory(this_object());
        if (sizeof(inventory))
        {
            foreach(object item in inventory)
            {
                destruct(item);
            }
        }
        destruct(this_object());
    }
}
