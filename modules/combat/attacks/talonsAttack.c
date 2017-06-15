//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    ::init();
    setDamageType("physical");
    addHitDictionary(({
        "slash", "slice", "gouge", "whack" }));

    addSimileDictionary(({
        "cutting ##TargetPossessive## ##BodyPart## deeply", "repeatedly in "
        "the ##BodyPart##", "with a ##BodyPart##-rending force" }));
        
    addMissMessage("##AttackerName## ##Infinitive::admire## ##AttackerPossessive##"
        " beautifully manicured talons.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## with ##AttackerPossessive## talons.","1-50");
}




