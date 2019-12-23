//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("poison");
        addHitDictionary(({
            "inject", "splatter", "spray" }));

        addSimileDictionary(({
            "with a sickening green poison", "with a jet of puce poison",
            "with a stream of inky black poison" }));

        addMissMessage("##AttackerName## ##Infinitive::dance## like "
            "##AttackerPossessive## pants are on fire!");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary##.", "1-150");
    }
}



