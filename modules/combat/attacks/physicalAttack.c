inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("physical");
    addHitDictionary(({
        "bash", "slam", "slap", "pummel", "crush", "pound", "punch", "smack",
        "assault" }));

    addSimileDictionary(({
        "smashing ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
        "the ##BodyPart##", "with a ##BodyPart##-shattering force" }));
        
    addMissMessage("##AttackerName## ##Infinitive::flail## wildly! Very theatric.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.","1-50");
}




