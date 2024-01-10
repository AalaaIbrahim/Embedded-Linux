

## Embedded Linux - Task 6

### Requirements

You are tasked to create a sd.img 

- size: 1GB
- Devided into two partitions:
  - boot: FAT partition of 200 mb
  - rootfs: EXT4 partition of 800 mb

### Implementation

1. **Create sd.img file**

   `dd if=/dev/zero of=sd.img bs=1M count=1024`

   to copy `1024` blocks of size `1 MB` from the file `/dev/zero` to the file `sd.img` which will be created in the current directory.

2. **Configure the SD partitions**

   `cfdisk sd.img`

   1. Select the disk label type to be **dos**.
   2. To create the *boot* partition:
      1. In the free space, create new partition.
      2. Configure the partition such that:
         - Size : 200 MB
         - Type: FAT16 (primary)
         - Bootable: yes
      3. Write the partition table to the disk.
   3. To create the *rootfs* partition:
      1. In the free space, create new partition.
      2. Configure the partition such that:
         - Size : 800 MB
         - Type: Linux (extendable)
         - Bootable: no
      3. Write the partition table to the disk.
   4. Quit program.

3. **Associate SD image with a loop device**

   `sudo losetup -f --partscan sd.img`

   This will attach the sd.img file with the first free loop device it can find allowing the file to be accessible as a block device so that it can be mounted to disk, read and written to like any physical storage device.

   Here, running `lsblk` command shows that the image was attached to loop17 device.

   ![image-20240109142133065](https://github.com/AalaaIbrahim/Embedded-Linux/assets/118854389/0803f2a3-6525-4fa6-b8d7-c5e82331f31d)

4. **Format Partitions**

   The mkfs.<type> command is used to make a file system of the given type on a given disk partition.

   `sudo mkfs.vfat -F 16 -n boot /dev/loop17p1`

   `sudo mkfs.ext4 -L rootfs /dev/loop17p2`

5. **Mount the SD Card**

   Mount each of the SD Card's partitions to a specific directory.

   `sudo mount /dev/loop17p1 ~/SD_Card/boot`

   `sudo mount /dev/loop17p2 ~/SD_Card/rootfs`



