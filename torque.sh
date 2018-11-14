#PBS -l nodes=1:ppn=1,mem=1gb,walltime=00:05:00
#PBS -M jc.giraldo10@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio27

cd /hpcfs/home/fisi4028/jc.giraldo10/JuanGiraldo_Ejercicio27/

module load mpich/3.2.1

make clean
make listing_122
make listing_123
