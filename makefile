listing_122: listing_122.c 
	mpicc listing_122.c -o listing_122
	mpirun -np 4 ./listing_122
	
listing_123: listing_123.c 
	mpicc listing_123.c -o listing_123
	mpirun -np 4 ./listing_123

clean:
	rm -f listing_122
	rm -f listing_123
