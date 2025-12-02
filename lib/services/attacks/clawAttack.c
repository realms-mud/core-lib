//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("physical");
    addHitDictionary(({
        "slash", "slice", "lacerate", "rip", "tear", "carve", "dissect" }));

    addSimileDictionary(({
        "across ##TargetPossessive## ##BodyPart##", "repeatedly in "
        "the ##BodyPart##", "savagely", "like a crazed butcher" }));

    addMissMessage("##AttackerName## ##Infinitive::bare## ##AttackerPossessive##"
        " claws and ##Infinitive::swat## at the air.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## with ##AttackerPossessive## claws.", "1-150");
}
