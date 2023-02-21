//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public void CreateAegisEquipment(object user)
{
    if (objectp(user))
    {
        object equipment = clone_object("/lib/instances/items/armor/medium-armor/chainmail.c");
        equipment.set("craftsmanship", 50);
        equipment.set("name", "aegis chainmail");
        equipment.set("short", "Aegis Chainmail");
        equipment.set("material", "steel");
        move_object(equipment, user);
        user.equip(equipment, 1);

        equipment = clone_object("/lib/instances/items/armor/accessories/boots.c");
        equipment.set("craftsmanship", 50);
        equipment.set("armor class", 1);
        move_object(equipment, user);
        user.equip(equipment, 1);

        equipment = clone_object("/lib/instances/items/armor/clothing/cloak.c");
        equipment.set("name", "aegis cloak");
        equipment.set("short", "Aegis Cloak");
        equipment.set("craftsmanship", 50);
        equipment.set("armor class", 1);
        move_object(equipment, user);
        user.equip(equipment, 1);

        equipment = clone_object("/lib/instances/items/armor/light-armor/leather-arm-greaves.c");
        equipment.set("craftsmanship", 50);
        equipment.set("armor class", 1);
        move_object(equipment, user);
        user.equip(equipment, 1);

        equipment = clone_object("/lib/instances/items/armor/light-armor/leather-leg-greaves.c");
        equipment.set("craftsmanship", 50);
        equipment.set("armor class", 1);
        move_object(equipment, user);
        user.equip(equipment, 1);
    }
}
