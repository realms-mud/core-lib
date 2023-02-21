//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("neutral");
    addHitDictionary(({
        "strike", "hit", "damage", "thump", "lash" }));

    addSimileDictionary(({
        "with waves of colorless energy", "with a shock of colorless force",
        "soundly", "resoundingly" }));

    addMissMessage("##AttackerName## ##Infinitive::get## a not-so-bright "
        "look on ##AttackerPossessive## face.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-150");
}
