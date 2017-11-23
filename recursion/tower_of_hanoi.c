#include <stdio.h>
// incomplete
void toh(unsigned int num_of_disks, unsigned int disks_at_from_tower[], char from_tower, char to_tower, char aux_tower)
{
	// if there is a single item, directly move it to to_tower
	if (1 == num_of_disks){
		printf("Move [%d]: [%c] --> [%c]\n", disks_at_from_tower[num_of_disks-1], from_tower, to_tower);
		return;
	}
	// move n-1 items to aux_tower, use to_tower as auxillary tower
	toh(num_of_disks-1, disks_at_from_tower, from_tower, aux_tower, to_tower);

	// move the last item to to_tower
	unsigned int remaining_disks[1];
	remaining_disks[0] = disks_at_from_tower[0];
	toh(1, remaining_disks, from_tower, to_tower, aux_tower);

	unsigned int disks_at_aux_tower[num_of_disks-1];
	int i=1;
	for(;i<num_of_disks; i++){
		disks_at_aux_tower[i-1] = disks_at_from_tower[i];
	} 
	// move n-1 items from aux_tower to to_tower
	toh(num_of_disks-1, disks_at_aux_tower, aux_tower, to_tower, from_tower); 
}

int main()
{
	unsigned int disks[3] = {3, 2, 1};
	toh(3, disks, 'F', 'T', 'A');
}
