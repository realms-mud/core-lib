DROP PROCEDURE IF EXISTS deleteResearchAndTreesFromLists;
##
CREATE PROCEDURE `deleteResearchAndTreesFromLists` ( p_playername varchar(40), 
    p_researchItems longtext, p_trees longtext
)
BEGIN
    declare localPlayerId int;

    select id into localPlayerId from players where name = p_playername;

	set @deleteResearch = concat('delete from research where playerid = ',
		localPlayerId, ' and path in (', p_researchItems, ');');
    prepare stmt from @deleteResearch;
    execute stmt;
    deallocate PREPARE stmt;
    
	set @deleteTrees = concat('delete from openResearchTrees where playerid = ',
		localPlayerId, ' and researchTree in (', p_trees, ');');
    prepare stmt from @deleteTrees;
    execute stmt;
    deallocate PREPARE stmt;
END;
##
DROP PROCEDURE IF EXISTS deleteCompositeResearchByConstraint;
##
CREATE PROCEDURE `deleteCompositeResearchByConstraint` ( 
    p_playername varchar(40), p_constraint longtext
)
BEGIN
    declare compositeId int;
    declare localPlayerId int;

    select id into localPlayerId from players where name = p_playername;

    select id into compositeId from compositeResearch
    where playerid = localPlayerId and 
          compositeResearch.constraint in (p_constraint);

    if compositeId is not null then
        delete from compositeResearchElements 
        where compositeresearchid = compositeId;

        delete from compositeResearch
        where id = compositeId;
    end if;
END;
##