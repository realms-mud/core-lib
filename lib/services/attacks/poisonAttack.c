//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
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
